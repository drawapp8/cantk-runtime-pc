/*
 * Copyright (c) 2014 Cesanta Software Limited
 * All rights reserved
 */

/*
 * === JSON-RPC
 */

#ifndef NS_JSON_RPC_HEADER_DEFINED
#define NS_JSON_RPC_HEADER_DEFINED

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* JSON-RPC request */
struct ns_rpc_request {
  struct json_token *message; /* Whole RPC message */
  struct json_token *id;      /* Message ID */
  struct json_token *method;  /* Method name */
  struct json_token *params;  /* Method params */
};

/* JSON-RPC response */
struct ns_rpc_reply {
  struct json_token *message; /* Whole RPC message */
  struct json_token *id;      /* Message ID */
  struct json_token *result;  /* Remote call result */
};

/* JSON-RPC error */
struct ns_rpc_error {
  struct json_token *message;       /* Whole RPC message */
  struct json_token *id;            /* Message ID */
  struct json_token *error_code;    /* error.code */
  struct json_token *error_message; /* error.message */
  struct json_token *error_data;    /* error.data, can be NULL */
};

/*
 * Parse JSON-RPC reply contained in `buf`, `len` into JSON tokens array
 * `toks`, `max_toks`. If buffer contains valid reply, `reply` structure is
 * populated. The result of RPC call is located in `reply.result`. On error,
 * `error` structure is populated. Returns: the result of calling
 * `parse_json(buf, len, toks, max_toks)`:
 *
 * On success, an offset inside `json_string` is returned
 * where parsing has finished. On failure, a negative number is
 * returned, one of:
 *
 *  - #define JSON_STRING_INVALID           -1
 *  - #define JSON_STRING_INCOMPLETE        -2
 *  - #define JSON_TOKEN_ARRAY_TOO_SMALL    -3
 */
int ns_rpc_parse_reply(const char *buf, int len, struct json_token *toks,
                       int max_toks, struct ns_rpc_reply *,
                       struct ns_rpc_error *);

/*
 * Create JSON-RPC request in a given buffer.
 *
 * Return length of the request, which
 * can be larger then `len` that indicates an overflow.
 * `params_fmt` format string should conform to `json_emit()` API,
 * see https://github.com/cesanta/frozen
 */
int ns_rpc_create_request(char *buf, int len, const char *method,
                          const char *id, const char *params_fmt, ...);

/*
 * Create JSON-RPC reply in a given buffer.
 *
 * Return length of the reply, which
 * can be larger then `len` that indicates an overflow.
 * `result_fmt` format string should conform to `json_emit()` API,
 * see https://github.com/cesanta/frozen
 */
int ns_rpc_create_reply(char *buf, int len, const struct ns_rpc_request *req,
                        const char *result_fmt, ...);

/*
 * Create JSON-RPC error reply in a given buffer.
 *
 * Return length of the error, which
 * can be larger then `len` that indicates an overflow.
 * `fmt` format string should conform to `json_emit()` API,
 * see https://github.com/cesanta/frozen
 */
int ns_rpc_create_error(char *buf, int len, struct ns_rpc_request *req,
                        int code, const char *message, const char *fmt, ...);

/* JSON-RPC standard error codes */
#define JSON_RPC_PARSE_ERROR (-32700)
#define JSON_RPC_INVALID_REQUEST_ERROR (-32600)
#define JSON_RPC_METHOD_NOT_FOUND_ERROR (-32601)
#define JSON_RPC_INVALID_PARAMS_ERROR (-32602)
#define JSON_RPC_INTERNAL_ERROR (-32603)
#define JSON_RPC_SERVER_ERROR (-32000)

/*
 * Create JSON-RPC error in a given buffer.
 *
 * Return length of the error, which
 * can be larger then `len` that indicates an overflow. See
 * JSON_RPC_*_ERROR definitions for standard error values:
 *
 * - #define JSON_RPC_PARSE_ERROR (-32700)
 * - #define JSON_RPC_INVALID_REQUEST_ERROR (-32600)
 * - #define JSON_RPC_METHOD_NOT_FOUND_ERROR (-32601)
 * - #define JSON_RPC_INVALID_PARAMS_ERROR (-32602)
 * - #define JSON_RPC_INTERNAL_ERROR (-32603)
 * - #define JSON_RPC_SERVER_ERROR (-32000)
 */
int ns_rpc_create_std_error(char *, int, struct ns_rpc_request *, int code);

typedef int (*ns_rpc_handler_t)(char *buf, int len, struct ns_rpc_request *);

/*
 * Dispatches a JSON-RPC request.
 *
 * Parses JSON-RPC request contained in `buf`, `len`.
 * Then, dispatches the request to the correct handler method.
 * Valid method names should be specified in NULL
 * terminated array `methods`, and corresponding handlers in `handlers`.
 * Result is put in `dst`, `dst_len`. Return: length of the result, which
 * can be larger then `dst_len` that indicates an overflow.
 * Overflown bytes are not written to the buffer.
 * If method is not found, an error is automatically generated.
 */
int ns_rpc_dispatch(const char *buf, int, char *dst, int dst_len,
                    const char **methods, ns_rpc_handler_t *handlers);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* NS_JSON_RPC_HEADER_DEFINED */

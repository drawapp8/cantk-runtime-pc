/*
 * Copyright (c) 2014 Cesanta Software Limited
 * All rights reserved
 */

#include "fossa.h"

/* RESTful server host and request URI */
static const char *s_target_address = "ajax.googleapis.com:80";
static const char *s_request = "/ajax/services/search/web?v=1.0&q=cesanta";

static int s_exit_flag = 0;

static void ev_handler(struct ns_connection *nc, int ev, void *ev_data) {
  struct http_message *hm = (struct http_message *) ev_data;
  int connect_status;

  switch (ev) {
    case NS_CONNECT:
      connect_status = * (int *) ev_data;
      if (connect_status == 0) {
        printf("Connected to %s, sending request...\n", s_target_address);
        ns_printf(nc, "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n",
                  s_request, s_target_address);
      } else {
        printf("Error connecting to %s: %s\n",
               s_target_address, strerror(connect_status));
        s_exit_flag = 1;
      }
      break;
    case NS_HTTP_REPLY:
      printf("Got reply:\n%.*s\n", (int) hm->body.len, hm->body.p);
      nc->flags |= NSF_SEND_AND_CLOSE;
      s_exit_flag = 1;
      break;
    default:
      break;
  }
}

int main(void) {
  struct ns_mgr mgr;
  struct ns_connection *nc;

  ns_mgr_init(&mgr, NULL);
  nc = ns_connect(&mgr, s_target_address, ev_handler);
  ns_set_protocol_http_websocket(nc);

  printf("Starting RESTful client against %s\n", s_target_address);
  while (s_exit_flag == 0) {
    ns_mgr_poll(&mgr, 1000);
  }
  ns_mgr_free(&mgr);

  return 0;
}

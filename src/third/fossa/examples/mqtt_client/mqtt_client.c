/*
 * Copyright (c) 2014 Cesanta Software Limited
 * All rights reserved
 * This software is dual-licensed: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation. For the terms of this
 * license, see <http://www.gnu.org/licenses/>.
 *
 * You are free to use this software under the terms of the GNU General
 * Public License, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * Alternatively, you can license this software under a commercial
 * license, as set out in <http://cesanta.com/>.
 */

#include "fossa.h"

struct ns_mqtt_topic_expression topic_expressions[] = {
  {"/stuff", 0}
};

static void ev_handler(struct ns_connection *nc, int ev, void *p) {
  struct ns_mqtt_message *msg = (struct ns_mqtt_message *)p;
  (void) nc;

#if 0
  if (ev != NS_POLL)
    printf("USER HANDLER GOT %d\n", ev);
#endif

  switch (ev) {
    case NS_CONNECT:
      ns_set_protocol_mqtt(nc);
      ns_send_mqtt_handshake(nc, "dummy");
      break;
    case NS_MQTT_CONNACK:
      if (msg->connack_ret_code != NS_MQTT_CONNACK_ACCEPTED) {
        printf("Got mqtt connection error: %d\n", msg->connack_ret_code);
        exit(1);
      }
      printf("Subscribing to '/stuff'\n");
      ns_mqtt_subscribe(nc, topic_expressions, sizeof(topic_expressions)/sizeof(*topic_expressions), 42);
      break;
    case NS_MQTT_PUBACK:
      printf("Message publishing acknowledged (msg_id: %d)\n", msg->message_id);
      break;
    case NS_MQTT_SUBACK:
      printf("Subscription acknowledged, forwarding to '/test'\n");
      break;
    case NS_MQTT_PUBLISH:
      {
#if 0
        char hex[1024] = {0};
        ns_hexdump(nc->recv_mbuf.buf, msg->payload.len, hex, sizeof(hex));
        printf("Got incoming message %s:\n%s", msg->topic, hex);
#else
        printf("Got incoming message %s: %.*s\n", msg->topic, (int)msg->payload.len, msg->payload.p);
#endif

        printf("Forwarding to /test\n");
        ns_mqtt_publish(nc, "/test", 65, NS_MQTT_QOS(0), msg->payload.p, msg->payload.len);
      }
      break;
    case NS_CLOSE:
      printf("Connection closed\n");
      exit(1);
  }
}

int main(void) {
  struct ns_mgr mgr;
  const char *address = "localhost:1883";

  ns_mgr_init(&mgr, NULL);

  if (ns_connect(&mgr, address, ev_handler) == NULL) {
    fprintf(stderr, "ns_connect(%s) failed\n", address);
    exit(EXIT_FAILURE);
  }

  for(;;) {
    ns_mgr_poll(&mgr, 1000);
  }
}

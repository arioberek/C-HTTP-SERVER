#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <microhttpd.h>

#define PORT 8888

MHD_Result handle_request(void *cls, struct MHD_Connection *connection,
                          const char *url, const char *method,
                          const char *version, const char *upload_data,
                          size_t *upload_data_size, void **con_cls)
{
  struct MHD_Response *response;

  if (strcmp(method, "GET") != 0)
  {
    return MHD_NO;
  }

   char buffer[] = "Hello, World!";

  response = MHD_create_response_from_buffer(strlen(buffer), buffer, MHD_RESPMEM_MUST_COPY);
  return MHD_queue_response(connection, MHD_HTTP_OK, response);
  MHD_destroy_response(response);
}

int main(int argc, char **argv)
{
  struct MHD_Daemon *daemon;

  daemon = MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION, PORT, NULL, NULL,
                            &handle_request, NULL, MHD_OPTION_END);

  printf("Server running on port %d\n", PORT);

  if (daemon == NULL)
  {
    fprintf(stderr, "Failed to start daemon\n");
    return 1;
  }

  getchar();

  MHD_stop_daemon(daemon);
  return 0;
}

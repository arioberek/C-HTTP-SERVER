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

  char method_not_allowed_response[] = "Method not allowed!";

  if (strcmp(method, "GET") != 0 && strcmp(method, "POST") != 0 && strcmp(method, "PUT") != 0 && strcmp(method, "DELETE") != 0 && strcmp(method, "PATCH") != 0)
  {
    response = MHD_create_response_from_buffer(strlen(method_not_allowed_response), method_not_allowed_response, MHD_RESPMEM_MUST_COPY);
    return MHD_NO;
  }

  char get_response[] = "[GET] You made a GET request!";
  char post_response[] = "[POST] You made a POST request!";
  char put_response[] = "[PUT] You made a PUT request!";
  char delete_response[] = "[DELETE] You made a DELETE request!";
  char patch_response[] = "[PATCH] You made a PATCH request!";

  if (strcmp(method, "GET") == 0)
  {
    response = MHD_create_response_from_buffer(strlen(get_response), get_response, MHD_RESPMEM_MUST_COPY);
  }

  if (strcmp(method, "POST") == 0)
  {
    response = MHD_create_response_from_buffer(strlen(post_response), post_response, MHD_RESPMEM_MUST_COPY);
  }

  if (strcmp(method, "PUT") == 0)
  {
    response = MHD_create_response_from_buffer(strlen(put_response), put_response, MHD_RESPMEM_MUST_COPY);
  }

  if (strcmp(method, "DELETE") == 0)
  {
    response = MHD_create_response_from_buffer(strlen(delete_response), delete_response, MHD_RESPMEM_MUST_COPY);
  }

  if (strcmp(method, "PATCH") == 0)
  {
    response = MHD_create_response_from_buffer(strlen(patch_response), patch_response, MHD_RESPMEM_MUST_COPY);
  }

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

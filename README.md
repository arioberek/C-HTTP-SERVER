# C REST API

  

#### This is a simple API written in C that returns "Hello, World!" when accessed via a GET request.

  

> The API uses the Micro HTTP Daemon (MHD) library to handle the HTTP request and response.

> The main function starts a daemon using MHD_start_daemon and sets the request handler function to handle_request. The handle_request function is called for each incoming request and checks that the request method is a GET request.

>If it is, it creates a response with a "Hello, World!" message and sends it back to the client. If the request method is not a GET, the function returns MHD_NO to indicate that it cannot handle the request. The API runs on port 8888 and prints a message to the console indicating that the server is running. The server will continue to run until the user enters a character, at which point the daemon is stopped and the program terminates.

  
  

## How to run

  

> Install the `microhttpd` lib (`sudo apt install libmicrohttpd-dev`)
> Install `gcc` (`sudo apt install gcc`)
>Run `gcc api.cpp -lmicrohttpd -o api` to compile the program
> Run `./api` to run the program
> Open a browser and go to `http://localhost:8888` to see the result or just run `curl http://localhost:8888` to see the result in the terminal

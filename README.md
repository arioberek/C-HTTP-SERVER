# HTTP Server in C 💻

This code is a C program that starts an HTTP server using the `microhttpd` library. The server listens for incoming HTTP requests on port 8888.

## Request Handling 📮

When a request is received, the server calls the `handle_request` function to process the request. The `handle_request` function first checks the method of the request (e.g. GET, POST, PUT, DELETE, PATCH). If the method is not one of these five, the server returns a "Method not allowed!" response.

If the method is allowed, the server creates a response based on the method. For example, if the method is GET, the server creates a response containing the text "[GET] You made a GET request!". The server then sends the response back to the client with a status code of 200 (OK).

## Getting started 🚀

- If you just want to run the already compiled version of the program, you can run `./api` in the terminal.

1. First, install the microhttpd library by running `sudo apt install libmicrohttpd-dev` in your terminal.

2. Next, install gcc by running `sudo apt install gcc`.

3. Use gcc to compile the program by running `gcc api.cpp -lmicrohttpd -o api`.

4. Run the program by entering `./api` in the terminal.

5. To see the result of the GET request, open a web browser and navigate to http://localhost:8888, or use curl to see the result in the terminal by running curl http://localhost:8888.

6. To see the result of POST, PUT, DELETE, and PATCH requests, use curl to send the request to the server. For example, to send a POST request, run `curl -X POST http://localhost:8888` (or use some tool like Postman or Insomnia).

## License 📜

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

## Acknowledgments 🙏

- [microhttpd](https://www.gnu.org/software/libmicrohttpd/) - The HTTP server library used

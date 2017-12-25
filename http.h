#ifndef TWES_HTTP_H
#define TWES_HTTP_H

#define BUFLEN 8096
#define ERR404 "404 Not Found"
#define ERR405 "405 Method Not Allowed"
#define ERR500 "500 Internal Server Error"
#define STATE200 "200 OK"
#define DEFAULTMIME "text/html"

typedef struct {
    char method[10];
    char protocol[10];
    char path[BUFLEN];
    char *headers;
} http_request;

enum {
    ERROR404,
    ERROR405,
    ERROR500
};

/**
 * Initialize http request
 */
http_request *init_http_request(char *buf);

/**
 * Clean request header
 */
void clean_http_request(http_request *req);

/**
 * Create http error
 */
void http_error( int connectfd, http_request *request, char *buf, const char *res_header,
                int err, const char *mime);


#endif //TWES_HTTP_H

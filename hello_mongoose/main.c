#include "mongoose.h"  // Include Mongoose API definitions


static const char *s_http_port = "8089";


// Define an event handler function
static void ev_handler(struct mg_connection *nc, int ev, void *ev_data) 
{
    struct mbuf *io = &nc->recv_mbuf;

    switch (ev) 
    {
    case MG_EV_RECV:

        // This event handler implements simple TCP echo server
        mg_send(nc, io->buf, io->len);  // Echo received data back

        mbuf_remove(io, io->len);      // Discard data from recv buffer

        break;

    default:
        break;
    }

    // handle your GET request to /hello
    char* content = "Hello World!";
    char* mimeType = "text/plain";
    int contentLength = strlen(content);

    mg_printf(nc,
        "HTTP/1.1 200 OK\r\n"
        "Cache: no-cache\r\n"
        "Content-Type: %s\r\n"
        "Content-Length: %d\r\n"
        "\r\n",
        mimeType,
        contentLength);
    mg_send(nc, content, contentLength);
}

int main(void)
{
    struct mg_mgr mgr;

    mg_mgr_init(&mgr, NULL);  // Initialize event manager object

    // Note that many connections can be added to a single event manager
    // Connections can be created at any point, e.g. in event handler    function
    mg_bind(&mgr, s_http_port, ev_handler);  // Create listening connection   and add it to the event manager

    for (;;) 
    {  
        // Start infinite event loop
        mg_mgr_poll(&mgr, 1000);
    }

    mg_mgr_free(&mgr);
    return 0;
}


LDFLAGS+=-Wl,--push-state,-Bstatic -lssl -lcrypto -Wl,--pop-state

FD_HAS_OPENSSL:=1
CPPFLAGS+=-DFD_HAS_OPENSSL=1

CPPFLAGS+=-DOPENSSL_API_COMPAT=30000 -DOPENSSL_NO_DEPRECATED
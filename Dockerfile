FROM alpine:latest

RUN apk update && apk add --no-cache gcc musl-dev su-exec

WORKDIR /workspace

COPY . /workspace/
COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/bin/sh", "/entrypoint.sh"]
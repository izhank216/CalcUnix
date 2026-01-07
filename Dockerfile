FROM gcc:latest AS builder

WORKDIR /CalcUnix

COPY . .

RUN make

FROM alpine:latest

WORKDIR /CalcUnix

COPY --from=builder /CalcUnix/calcunix .
COPY --from=builder /CalcUnix/Calculate.so .

RUN chmod +x calcunix

CMD ["./calcunix"]

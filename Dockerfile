# Build stage with GCC
FROM gcc:latest AS builder

WORKDIR /CalcUnix

COPY . .

# Build the shared library and binary
RUN make

# Runtime stage: scratch (empty container)
FROM scratch

WORKDIR /CalcUnix

# Copy the built binary and shared library
COPY --from=builder /CalcUnix/calcunix .
COPY --from=builder /CalcUnix/Calculate.so .

# Ensure the binary is executable
COPY --from=builder /CalcUnix/calcunix ./calcunix
COPY --from=builder /CalcUnix/Calculate.so ./Calculate.so

CMD ["/CalcUnix/calcunix"]

# Minitalk

Signal-based IPC for the 42 curriculum. `server` and `client` communicate using `SIGUSR1`/`SIGUSR2` to transmit a message bit-by-bit.

## Requirements
- **OS:** Unix-like (Linux/macOS)
- **Compiler:** `cc`
- **Flags:** `-Wall -Wextra -Werror`
- **Build:** `make` (Norminette-compliant)

## Build
```bash
make         # builds server and client
make clean   # remove .o
make fclean  # remove .o and binaries
make re      # full rebuild
```

## Usage
Start the server (prints its PID):
```bash
./server
# Example output: "PID: 42421"
```
Send a message from the client:
```bash
./client 42421 "Hello from minitalk!"
```

## Protocol
- **Signals:** use `SIGUSR1` and `SIGUSR2` to encode bits.
- **Encoding:** transmit each character as 8 bits (LSB → MSB or MSB → LSB, but be consistent on both ends).
- **Message end:** send a `'\0'` byte to signal end-of-message; the server prints the accumulated string.
- **Timing:** introduce a small delay between signals to avoid loss (e.g., `usleep`); bonus may rely on per-bit or per-char acknowledgments to avoid busy-waiting.
- **UTF‑8:** messages are treated as raw bytes; multi-byte characters are forwarded unchanged (no transcoding).

## API (internal helpers)
Typical internal functions (names may vary):
- `send_bit(pid_t pid, int bit)` — sends a single bit via a chosen signal.
- `send_byte(pid_t pid, unsigned char c)` — sends 8 bits in order.
- `handler(int signum, siginfo_t *info, void *ctx)` — accumulates bits/bytes on the server side.
- `safe_write(const char *s, size_t len)` — minimal I/O wrapper using `write(2)`.

## Bonus Ideas (commonly expected)
- **Acknowledgments:** server `kill(client_pid, SIGUSR1)` after each bit/char; client blocks until ACK (improves reliability and throughput without arbitrary sleeps).
- **Received counter:** server tracks printed bytes; client prints "Delivered: N" at completion.
- **Unicode/long messages:** confirm correct handling of long UTF‑8 strings and large payloads.
- **Error handling:** validate PID, handle `kill` failures, and guard against `NULL`/empty messages.

## Testing
- Edge cases: empty string, very long string, messages with `\n` and non-ASCII bytes, invalid PID, rapid successive sends, multiple clients.
- Stress: send a few thousand characters and check integrity and absence of dropped bits.

## Notes
- Use of `sigaction` with `SA_SIGINFO` for reliable sender PID retrieval and reentrancy; keep handlers async-signal-safe (only set flags, write to pipe, or use `write`).
- Avoid global state beyond the minimal static storage allowed by the subject.
- Throttle carefully if not using ACKs; too little delay can cause missed signals.
- All code follows the 42 Norm.

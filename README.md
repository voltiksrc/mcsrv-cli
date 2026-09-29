# Mcsrv-cli

A MC tool that displays a tiny dashboard of info on any Minecraft server you point it to.

## Usage

```bash
mcsrv-cli <server-address>
```

Example:

```bash
mcsrv-cli play.cubecraft.net
```

Output:

```text
Server: play.cubecraft.net
Online: true
IP: 193.105.184.233
Port: 25565
Version: We support: 1.20-1.21
Protocol: 1.12.2
Players online: 809 / 5000
```

## Installation

Build with Meson:

```bash
meson setup build
meson compile -C build
```

Install system-wide:

```bash
sudo install -m 755 build/mcsrv-cli /usr/local/bin/mcsrv-cli
```

Then run it from anywhere:

```bash
mcsrv-cli play.cubecraft.net
```

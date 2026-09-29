# Mcsrv-cli
A MC tool that displays a tiny dashboard of info on any minecraft server you point it to.

# Usage
mcsrv-cli <server-address>


Example:$ mcsrv-cli play.cubecraft.net
Server: play.cubecraft.net
Online: true
IP: 193.105.184.233
Port: 25565
Version: We support: 1.20-1.21
Protocol: 1.12.2
Players online: 809 / 5000

## Installation

Build with Meson:

```bash
meson setup build
meson compile -C build


Install system-wide:

```bash
sudo install -m 755 build/mcsrv-cli /usr/local/bin/mcsrv-cli

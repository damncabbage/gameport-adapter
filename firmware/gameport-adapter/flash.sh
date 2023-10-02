#!/usr/bin/env bash

SCRIPT_DIR=$(unset CDPATH; cd "$(dirname "$0")" && pwd)
set -eux

if [ ! -d "${SCRIPT_DIR}/venv" ]; then
  python -mvenv venv
  . venv/bin/activate.sh
  pip install platformio
else
  . venv/bin/activate.sh
fi

platformio run -t upload --upload-port /dev/cu.usbmodem*

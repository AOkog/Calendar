#!/bin/bash
set -e

# Use host.docker.internal for Windows, fallback to :0
export DISPLAY=${DISPLAY:-host.docker.internal:0.0}

./build/calendar-app
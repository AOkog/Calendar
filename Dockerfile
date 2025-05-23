FROM ubuntu:22.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential cmake qtbase5-dev qt5-qmake \
    libx11-dev libxext-dev libxrender-dev libxcb1-dev libx11-xcb-dev \
    x11-apps

# Create app directory
WORKDIR /app

# Copy source and resources
COPY . .

# Build app
RUN cmake -S . -B build && cmake --build build

# Use a start script to launch the app
CMD ["./start.sh"]

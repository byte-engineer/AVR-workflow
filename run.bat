docker build -t avr-dev .
docker run -it --rm -v $(pwd):/workspace avr-dev
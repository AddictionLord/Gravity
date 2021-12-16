xhost +
docker run -it --rm --privileged --net=host --env=DISPLAY --volume="$(pwd)/:/tmp" --volume="/tmp/.X11-unix:/.X11-unix:ro" -w /tmp sfml-docker:v1.1 bash 

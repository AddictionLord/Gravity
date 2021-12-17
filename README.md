First build docker image from Dockerfile

```
./setup_docker.sh
```

Then run docker with X11 forwarding to enable GUI apps

```
./run_docker.sh
```

Create build directory, build project

```
mkdir build && cd build && cmake .. && make -j 
```

Run project

```
./gravity
```

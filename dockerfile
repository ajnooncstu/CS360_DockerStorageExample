FROM ubuntu
COPY writedata /
CMD ["/writedata", "/logs/myapp"]
  

mymodule:
	g++ -fPIC -shared -I/usr/include/python3.6 mymodule.cc -o mymodule.so

clean:
	rm *.so

spam:
	g++ -fPIC -shared -I/usr/include/python3.6 spam.cc -o spam.so

clean:
	rm *.so

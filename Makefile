compile: qu_scene.cpp
	@clear
	@echo "Compile qu_scene"
	@g++ -Wall qu_scene.cpp -Wl,-rpath,/usr/local/lib -l kaitai_struct_cpp_stl_runtime -o test

run: test
	./test
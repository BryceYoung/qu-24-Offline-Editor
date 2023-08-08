compile: qu_scene.o QU24-Offline-Editor.o
	@echo "Compiling ALL"
	@g++ -o test qu_scene.o QU24-Offline-Editor.o -Wl,-rpath,/usr/local/lib -l kaitai_struct_cpp_stl_runtime

QU24-Offline-Editor.o: QU24-Offline-Editor.cpp
	@echo "Compile QU24-Offline-Editor"
	@g++ -g -Wall -c QU24-Offline-Editor.cpp -Wl,-rpath,/usr/local/lib -l kaitai_struct_cpp_stl_runtime

qu_scene.o: qu_scene.cpp 
	@echo "Compile qu_scene"
	@g++ -g -Wall -c qu_scene.cpp -Wl,-rpath,/usr/local/lib -l kaitai_struct_cpp_stl_runtime

run: test
	@echo "Test"
	@./test

run_test: test
	valgrind --leak-check=yes test
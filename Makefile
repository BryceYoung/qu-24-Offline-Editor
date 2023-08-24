compile: qu_scene.o QU24-Offline-Editor.o GUI.o
	@echo "Compiling ALL"
	@g++ -o test GUI.o qu_scene.o QU24-Offline-Editor.o -Wl,-rpath,/usr/local/lib -l kaitai_struct_cpp_stl_runtime `pkg-config gtkmm-3.0 --cflags --libs`

QU24-Offline-Editor.o: src/QU24-Offline-Editor.cpp include/QU24-Offline-Editor.h
	@echo "Compile QU24-Offline-Editor"
	@g++ -g -Wall -c src/QU24-Offline-Editor.cpp -Wl,-rpath,/usr/local/lib -l kaitai_struct_cpp_stl_runtime

qu_scene.o: src/qu_scene.cpp include/qu_scene.h
	@echo "Compile qu_scene"
	@g++ -g -Wall -c src/qu_scene.cpp -Wl,-rpath,/usr/local/lib -l kaitai_struct_cpp_stl_runtime

GUI.o: src/GUI.cpp src/GUI.css include/GUI.h
	@echo "Compile GUI"
	@g++ -g -Wall -c src/GUI.cpp `pkg-config gtkmm-3.0 --cflags --libs`
run: test
	@echo "Test"
	@./test

run_test: test
	valgrind --leak-check=yes test

clean:
	@echo "Clean"
	@rm *.o
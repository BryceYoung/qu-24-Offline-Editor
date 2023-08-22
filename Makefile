compile: qu_scene.o QU24-Offline-Editor.o GUI.o
	@echo "Compiling ALL"
	@g++ -o test GUI.o qu_scene.o QU24-Offline-Editor.o -Wl,-rpath,/usr/local/lib -l kaitai_struct_cpp_stl_runtime `pkg-config gtkmm-3.0 --cflags --libs`

QU24-Offline-Editor.o: QU24-Offline-Editor.cpp QU24-Offline-Editor.h
	@echo "Compile QU24-Offline-Editor"
	@g++ -g -Wall -c QU24-Offline-Editor.cpp -Wl,-rpath,/usr/local/lib -l kaitai_struct_cpp_stl_runtime

qu_scene.o: qu_scene.cpp qu_scene.h
	@echo "Compile qu_scene"
	@g++ -g -Wall -c qu_scene.cpp -Wl,-rpath,/usr/local/lib -l kaitai_struct_cpp_stl_runtime

GUI.o: GUI.cpp GUI.css GUI.h
	@echo "Compile GUI"
	@g++ -g -Wall -c GUI.cpp `pkg-config gtkmm-3.0 --cflags --libs`
run: test
	@echo "Test"
	@./test

run_test: test
	valgrind --leak-check=yes test

windows: GUI.o QU24-Offline-Editor.o qu_scene.o
	x86_64-w64-mingw32-g++ -o windows GUI.o QU24-Offline-Editor.o qu_scene.o -Wl,-rpath,/usr/local/lib -l kaitai_struct_cpp_stl_runtime `pkg-config gtkmm-3.0 --cflags --libs`

clean:
	@echo "Clean"
	@rm *.o
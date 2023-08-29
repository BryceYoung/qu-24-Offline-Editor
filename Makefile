INCLUDEGUI := -Iinclude -Iinclude/GUI

Kaitai := -Wl,-rpath,/usr/local/lib -l kaitai_struct_cpp_stl_runtime

GTKMM := `pkg-config gtkmm-3.0 --cflags --libs`

compile: qu_scene.o QU24-Offline-Editor.o GUI.o Fader.o GUIScene.o MyWindow.o
	@g++ -o test GUI.o Fader.o GUIScene.o MyWindow.o qu_scene.o QU24-Offline-Editor.o \
			$(INCLUDEGUI) $(Kaitai)	$(GTKMM)
	@echo "Compiled ALL"

QU24-Offline-Editor.o: src/QU24-Offline-Editor.cpp include/QU24-Offline-Editor.h
	@g++ -g -Wall -c src/QU24-Offline-Editor.cpp
	@echo "Compiled QU24-Offline-Editor"

qu_scene.o: src/qu_scene.cpp include/qu_scene.h
	@g++ -g -Wall -c src/qu_scene.cpp
	@echo "Compiled qu_scene"

GUI.o: src/GUI.cpp include/GUI.h QU24-Offline-Editor.o qu_scene.o
	@g++ -g -Wall -c src/GUI.cpp $(INCLUDEGUI) $(GTKMM)

Fader.o: src/GUI/Fader.cpp include/GUI/Fader.h QU24-Offline-Editor.o qu_scene.o
	@g++ -g -Wall -c src/GUI/Fader.cpp $(INCLUDEGUI) $(GTKMM)
	@echo "Compiled Fader" 

GUIScene.o: src/GUI/GUIScene.cpp include/GUI/GUIScene.h QU24-Offline-Editor.o qu_scene.o
	@g++ -g -Wall -c src/GUI/GUIScene.cpp $(INCLUDEGUI) $(GTKMM)
	@echo "Compiled GUIScene"

MyWindow.o: src/GUI/MyWindow.cpp include/GUI/MyWindow.h QU24-Offline-Editor.o qu_scene.o
	@g++ -g -Wall -c src/GUI/MyWindow.cpp $(INCLUDEGUI) $(GTKMM)
	@echo "Compiled MyWindow"

run: test compile
	@echo "Test"
	@./test

run_test: test compile
	valgrind --leak-check=yes test

run_GUI: test compile
	GTK_DEBUG=interactive ./test

clean:
	@echo "Clean"
	@rm *.o

all: compile
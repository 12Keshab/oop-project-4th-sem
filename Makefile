CXX = g++

CXXFLAGS = -Iinclude -std=c++17

SRC = src/main.cpp \
      src/guest.cpp \
      src/hotel_manager.cpp \
      src/reservation.cpp \
      src/room.cpp

TARGET = app

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run:
	.\$(TARGET).exe

clean:
	del /Q $(TARGET).exe
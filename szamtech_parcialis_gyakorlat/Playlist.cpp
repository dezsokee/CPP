#include <iostream>
#include "Playlist.h"

Playlist::Playlist(int capacity) {
    this->capacity = capacity;

    list = new Video *[capacity];

    for(int i = 0; i < capacity; i++) {
        list[i] = new Video[capacity];
    }
}

Playlist::Playlist(const Playlist &copy) {
    this->capacity = copy.capacity;
    this->title = copy.title;
    this->count = copy.count;

    list = new Video *[capacity];

    for(int i = 0; i < capacity; i++) {
        list[i] = nullptr;
    }

    for (int i = 0; i < count; ++i) {
        this->list[i] = copy.list[i];
    }
}

Playlist::Playlist(Playlist &&move) noexcept {
    this->capacity = move.capacity;
    this->title = move.title;
    this->count = move.count;

    this->list = move.list;

    move.capacity = 0;
    move.title = nullptr;
    move.count = 0;

    move.list = nullptr;
}

Playlist::~Playlist() {
    for (int i = 0; i < capacity; ++i) {
        delete[] list[i];
    }

    delete[] list;
}

const string &Playlist::getTitle() const {
    return title;
}

void Playlist::setTitle(const string &title) {
    Playlist::title = title;
}

int Playlist::videos() const {
    return this->count;
}

void Playlist::append(Video *video) {
    if(count < capacity) {
        list[count] = video;
        count++;
    }
}

void Playlist::sort(bool (*less)(const Video &, const Video &)) {
    for (int i = 0; i < count; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if(less(*list[i], *list[j])) {
                Video *temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

}

Video *Playlist::operator[](int index) {
    return list[index];
}

const Video *Playlist::operator[](int index) const {
    return list[index];
}

Playlist &Playlist::operator=(const Playlist &copy) {
    if(this != &copy) {
        for (int i = 0; i < capacity; ++i) {
            delete[] list[i];
        }

        delete[] list;

        this->capacity = 0;
        this->count = 0;
        this->title = nullptr;

        this->capacity = copy.capacity;
        this->count = copy.count;
        this->title = copy.title;

        list = new Video *[capacity];

        for(int i = 0; i < capacity; i++) {
            list[i] = nullptr;
        }

        for (int i = 0; i < count; ++i) {
            list[i]=copy.list[i];
        }
    }

    return *this;
}

Playlist &Playlist::operator=(const Playlist &&move) noexcept {
    for (int i = 0; i < capacity; ++i) {
        delete[] list[i];
    }

    delete[] list;

    this->capacity = move.capacity;
    this->count = move.count;
    this->title = move.title;

    list = new Video *[capacity];

    this->list = move.list;

    return *this;
}

Playlist operator+(const Playlist &a, const Playlist &b) {
    Playlist p1(a.capacity+b.capacity);

    for (int i = 0; i < a.capacity; ++i) {
        p1.list[i] = a.list[i];
    }

    for (int i = 0; i < b.capacity; ++i) {
        p1.list[i] = b.list[i];
    }

    return p1;
}

ostream &operator<<(ostream &os, const Playlist &list) {
    cout<<list.title<<": "<<endl;

    for (int i = 0; i < list.capacity; ++i) {
        cout<<i+1<<". "<<list[i]<<endl;
    }
}





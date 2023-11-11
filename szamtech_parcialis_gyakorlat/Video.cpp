#include <iostream>
#include "Video.h"

using namespace std;

Video::Video(const string &id, const string &title, double length, const string &uploader, long uploaded) {
    this->id = id;
    this->title = title;
    this->length = length;
    this->uploader = uploader;
    this->uploaded = uploaded;
}

const string &Video::getId() const {
    return id;
}

const string &Video::getTitle() const {
    return title;
}

double Video::getLength() const {
    return length;
}

const string &Video::getUploader() const {
    return uploader;
}

long Video::getUploaded() const {
    return uploaded;
}

ostream &operator<<(ostream &os, const Video &video) {
    os<<"ID: "<<video.getId()<<" - "<<video.getTitle()<<" length: "<<video.getLength()<<", uploaded by "<<video.getUploader()<<" in "<< video.getUploaded()<<endl;
    return os;
}

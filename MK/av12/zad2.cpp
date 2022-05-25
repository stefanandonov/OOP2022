#include<iostream>
#include<cstring>

using namespace std;
enum AudioFormat {
    mp3, wav, ogg, flac
};

enum VideoCompression {
    x264, Theora, AV1
};

class MediaSegment { //abstract
protected:
    char title[100];
    char author[100];
    int duration;
    int size;
public:
    MediaSegment(char *title = "", char *author = "", int duration = 0, int size = 0) {
        strcpy(this->author, author);
        strcpy(this->title, title);
        this->duration = duration;
        this->size = size;
    }

    virtual double price() const = 0;
};

class AudioRecording : virtual public MediaSegment {
protected:
    AudioFormat format;
    short channels;
public:
    AudioRecording(char *title = "", char *author = "", int duration = 0, int size = 0, int format = 0,
                   short channels = 0)
            : MediaSegment(title, author, duration, size) {
        this->format = (AudioFormat) format;
        this->channels = channels;
    }

    double price() const {
        double product = duration * channels;
        if (format == flac) {
            product *= 1.5;
        }
        return product;
    }

    friend ostream &operator<<(ostream &out, const AudioRecording &ar) {
        return out << ar.title << " - " << ar.author << " - " << ar.duration << " - " << ar.size << " - " << ar.price();
    }
};

class VideoRecording : virtual public MediaSegment {
protected:
    int width;
    VideoCompression compression;
public:
    VideoRecording(char *title = "", char *author = "", int duration = 0, int size = 0, int width = 0,
                   int compression = 0)
            : MediaSegment(title, author, duration, size) {
        this->width = width;
        this->compression = (VideoCompression) compression;
    }

    double price() const {
        double price;
        if (width <= 1920) {
            price = 100 * duration;
        } else {
            price = 170 * duration;
        }

        if (compression == x264) {
            price *= 1.5;
        } else if (compression == Theora) {
            price *= 0.9;
        }

        return price;
    }

    friend ostream &operator<<(ostream &out, const VideoRecording &vr) {
        return out << vr.title << " - " << vr.author << " - " << vr.duration << " - " << vr.size << " - " << vr.width
                   << " - " << vr.price();
    }
};

class MusicVideo : public AudioRecording, public VideoRecording {
private:
    char date[9];
public:
    MusicVideo(char *title = "", char *author = "", int duration = 0, int size = 0, int format = 0,
               short channels = 0, int width = 0, int compression = 0, char *date = "01012020") :
            MediaSegment(title, author, duration, size) {
        this->format = (AudioFormat) format;
        this->channels = channels;
        this->width = width;
        this->compression = (VideoCompression) compression;
        strcpy(this->date, date);
    }

    double price() const {
        double result = AudioRecording::price() + VideoRecording::price();
        char year[5];
//        strcpy(year, date+4);
//        int yearInt = atoi(year);
//        strcmp(year, "2010")>0;
        if (strcmp(date + 4, "2010") > 0) {
            result *= 1.3;
        }
        return result;
    }

    friend ostream &operator<<(ostream &out, const MusicVideo &mv) {
        return out << mv.title << " - " << mv.author << " - " << mv.date << " - " << mv.duration << " - " << mv.price();
    }
};

double total_price(MediaSegment **segments, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += segments[i]->price();
    }
    return sum;
}

MusicVideo cheapest_music_video(MediaSegment **segments, int n) {
    MusicVideo *min = nullptr;
    for (int i = 0; i < n; i++) {
        MusicVideo *casted = dynamic_cast<MusicVideo *>(segments[i]);
        if (casted) {
            if (min == nullptr) {
                min = casted;
            } else if (casted->price() < min->price()) {
                min = casted;
            }
        }
    }
    return *min;
}

int main() {

    int test_case_num;
    cin >> test_case_num;


    // for MediaSegment
    char title[100];
    char author[1000];
    unsigned int size;
    unsigned int duration;


    // for AudioRecording
    //-------------------
    unsigned short channels;

    // AudioFormat:
    // 0 - mp3
    // 1 - wav
    // 2 - ogg
    // 3 - flac
    unsigned short format;


    // for VideoRecording
    //-------------------
    unsigned short width;

    // VideoCompression:
    // 0 - x264
    // 1 - Theora
    // 2 - AV1
    int compression;


    // for MusicVideo
    //-------------------
    char publication_date[9];


    if (test_case_num == 1) {
        cout << "Testing class AudioRecording and operator<<" << std::endl;
        cin.get();
        cin.getline(title, 100);
        cin.getline(author, 100);
        //cin.get();
        cin >> duration >> size;
        cin >> format >> channels;

        AudioRecording a(title, author, duration, size, format, channels);

        cout << a;

    } else if (test_case_num == 2) {
        cout << "Testing class VideoRecording and operator<<" << std::endl;
        cin.get();
        cin.getline(title, 100);
        cin.getline(author, 100);
        //cin.get();
        cin >> duration >> size;
        cin >> width >> compression;

        VideoRecording v(title, author, duration, size, width, compression);

        cout << v;

    } else if (test_case_num == 3) {
        cout << "Testing class MusicVideo and operator<<" << std::endl;

        cin.get();
        cin.getline(title, 100);
        cin.getline(author, 100);
        //cin.get();
        cin >> duration >> size;

        cin >> format >> channels;
        cin >> width >> compression;

        cin.get();
        cin.getline(publication_date, 9);
        MusicVideo mv(title, author, duration, size, format, channels, width, compression, publication_date);

        cout << mv;
    } else if (test_case_num == 4) {
        cout << "Testing function: total_price " << std::endl;

        MediaSegment **m;

        int num_media_segments;
        cin >> num_media_segments;

        // 1 - AudioRecording
        // 2 - VideoRecording
        // 3 - MusicVideo
        short media_type;

        m = new MediaSegment *[num_media_segments];

        for (int i = 0; i < num_media_segments; i++) {

            cin >> media_type;

            cin.get();
            cin.getline(title, 100);
            cin.getline(author, 100);
            //cin.get();
            cin >> duration >> size;

            switch (media_type) {
                case 1:
                    cin >> format >> channels;
                    m[i] = new AudioRecording(title, author, duration, size, format, channels);
                    break;
                case 2:
                    cin >> width >> compression;
                    m[i] = new VideoRecording(title, author, duration, size, width, compression);
                    break;
                case 3:
                    cin >> format >> channels;
                    cin >> width >> compression;
                    cin.get();
                    cin.getline(publication_date, 9);
                    m[i] = new MusicVideo(title, author, duration, size, format, channels, width, compression,
                                          publication_date);
                    break;
            }
        }

        //for (int i=0;i<num_media_segments; i++){
        //    cout << *m[i];
        //}

        cout << "Total price is: " << total_price(m, num_media_segments);

        delete[] m;

    } else if (test_case_num == 5) {
        cout << "Testing function: cheapest_music_video " << std::endl;

        MediaSegment **m;

        int num_media_segments;
        cin >> num_media_segments;

        // 1 - AudioRecording
        // 2 - VideoRecording
        // 3 - MusicVideo
        short media_type;

        m = new MediaSegment *[num_media_segments];

        for (int i = 0; i < num_media_segments; i++) {

            cin >> media_type;

            cin.get();
            cin.getline(title, 100);
            cin.getline(author, 100);
            //cin.get();
            cin >> duration >> size;

            switch (media_type) {
                case 1:
                    cin >> format >> channels;
                    m[i] = new AudioRecording(title, author, duration, size, format, channels);
                    break;
                case 2:
                    cin >> width >> compression;
                    m[i] = new VideoRecording(title, author, duration, size, width, compression);
                    break;
                case 3:
                    cin >> format >> channels;
                    cin >> width >> compression;
                    cin.get();
                    cin.getline(publication_date, 9);
                    m[i] = new MusicVideo(title, author, duration, size, format, channels, width, compression,
                                          publication_date);
                    break;
            }
        }

        cout << cheapest_music_video(m, num_media_segments);

        delete[] m;
    }

    return 0;
}

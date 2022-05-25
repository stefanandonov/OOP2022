#include<iostream>
#include<cstring>

using namespace std;

class MediaSegment {
protected:
    char title[100];
    char author[100];
    int duration;
    int size;
public:
    MediaSegment(char title[100] = "", char author[100] = "", int duration = 0, int size = 0) {
        strcpy(this->title, title);
        strcpy(this->author, author);
        this->duration = duration;
        this->size = size;
    }

    virtual double price() const = 0; //pure-virtual method


};

enum AudioFormat {
    mp3, wav, ogg, flac
};

class AudioRecording : virtual public MediaSegment {
protected:
    AudioFormat format;
    short channels;
public:
    AudioRecording(char title[100] = "", char author[100] = "", int duration = 0, int size = 0, int format = 0,
                   short channels = 0)
            : MediaSegment(title, author, duration, size) {
        this->format = (AudioFormat) format;
        this->channels = channels;
    }

    //TODO implement methods
    double price() const {
        double result = duration * channels;
        if (format == flac) {
            result *= 1.5;
        }
        return result;
    }

    friend ostream &operator<<(ostream &out, const AudioRecording &ar) {
        //Title - Author - Duration - Size - Price
        return out << ar.title << " - " << ar.author << " - " << ar.duration << " - " << ar.size << " - " << ar.price();
    }
};

enum CompressionFormat {
    x264, Theora, AV1
};

class VideoRecording : virtual public MediaSegment {
protected:
    int width;
    CompressionFormat compressionFormat;
public:
    VideoRecording(char title[100] = "", char author[100] = "", int duration = 0, int size = 0, int width = 0,
                   int format = 0)
            : MediaSegment(title, author, duration, size) {
        this->width = width;
        this->compressionFormat = (CompressionFormat) format;
    }

    //TODO implement methods
    double price() const {
        double result;
        if (width <= 1920) {
            result = duration * 100; //100euros/second
        } else {
            result = duration * 170; //170 euros/second
        }

        if (compressionFormat == x264) {
            result *= 1.5;
        } else if (compressionFormat == Theora) {
            result *= 0.9;
        }
        return result;
    }

    friend ostream &operator<<(ostream &out, const VideoRecording &vr) {
        //Title - Author - Duration - size - dimension - price
        return out << vr.title << " - " << vr.author << " - " << vr.duration << " - " << vr.size << " - " << vr.width
                   << " - " << vr.price();
    }

};

class MusicVideo : public AudioRecording, public VideoRecording {
private:
    //01234567
    //ddmmgggg
    char date[9];
public:
    MusicVideo(char title[100], char author[100], int duration, int size, int format, short channels, int width,
               int compression, char date[9]) : MediaSegment(title, author, duration, size) {
        this->format = (AudioFormat) format;
        this->channels = channels;
        this->width = width;
        this->compressionFormat = (CompressionFormat) compression;
        strcpy(this->date, date);
    }

    double price() const {
        double result = AudioRecording::price() + VideoRecording::price();
//        int year = (date[4] - '0') * 1000 + (date[5] - '0') * 100 + (date[6] - '0') * 10 + (date[7] - '0');
        int year = atoi(date + 4);
        if (year > 2010) {
            result *= 1.3;
        }
        return result;
    }

    friend ostream &operator<<(ostream &out, const MusicVideo &mv) {
        //Title - Author - Date of publication - Duration - Price
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
    MusicVideo *cheapest = nullptr;
    for (int i = 0; i < n; i++) {
        MusicVideo *castedMusicVideo = dynamic_cast<MusicVideo *>(segments[i]);
        if (castedMusicVideo != 0) {
            if (cheapest == nullptr) { //we've found the first MusicVideo between the media segment
                cheapest = castedMusicVideo;
            }
            else if (castedMusicVideo->price() < cheapest->price()) {
                cheapest = castedMusicVideo;
            }
        }
    }
    return *cheapest;

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

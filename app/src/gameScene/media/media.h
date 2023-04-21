#pragma once

#include <QString>

class QMediaPlayer;
class QMediaPlaylist;

namespace Scene
{
class Media
{
public:
    Media();

    void addMedia(QString mediaPath, int volume);
    void play();

private:
    QMediaPlayer *_mediaPlayer;
    QMediaPlaylist *_playlist;
};

} // namespace Scene

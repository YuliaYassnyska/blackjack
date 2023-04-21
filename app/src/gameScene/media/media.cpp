#include "media.h"

#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Scene
{
Media::Media() : _mediaPlayer{ new QMediaPlayer() }, _playlist{ new QMediaPlaylist() }
{
    _mediaPlayer->setPlaylist(_playlist);
}

void Media::addMedia(QString mediaPath, int volume)
{
    _playlist->addMedia(QUrl(mediaPath));
    _mediaPlayer->setVolume(volume);
}

void Media::play()
{
    _mediaPlayer->play();
}
} // namespace Scene

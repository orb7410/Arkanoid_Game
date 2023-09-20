#include <iostream> //std::cout
#include "audio.hpp"

namespace arkanoid {

Audio::Audio(std::string const& a_audioName)
: m_buffer()
, m_sound()
, m_isPlay(false)
{
	if (!m_buffer.loadFromFile(a_audioName)) {
       throw "cant load audio file";
    }
    m_sound.setVolume(50);
	m_sound.setPlayingOffset(sf::seconds(3));
    m_sound.setBuffer(m_buffer);
    m_sound.setLoop(true);
}

void Audio::play() 
{
    m_isPlay = true;
    m_sound.play();
}

void Audio::pause()
{
    m_isPlay = false;
    m_sound.stop();
}

bool Audio::isPlaying() const noexcept
{
    return m_isPlay;
}


}//arkanoid

#include <SFML/Audio.hpp> 

namespace arkanoid {

class Audio {
public:                                                            
    Audio(std::string const& a_audioName);  
    Audio(const Audio &a_other) = delete;                                      
    Audio& operator=(const Audio &a_other) = delete;  
    ~Audio() = default;

    void play();
    void pause();
    bool isPlaying() const noexcept;

private:
    sf::SoundBuffer m_buffer;
    sf::Sound m_sound;
    bool m_isPlay = false;
};
} // arkanoid

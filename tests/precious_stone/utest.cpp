#include "mu_test.h"

#include <sstream>

#include "message.hpp"
#include "stream_source.hpp"
#include "stream_destination.hpp"
#include "udp_source.hpp"
#include "convert_caesar.hpp"
#include "file_source.hpp"
#include "file_destination.hpp"
#include "convert_vowel.hpp"
#include "convert_capitalize.hpp"
#include "black_box.hpp"

BEGIN_TEST(black_box_consol_consol_caeser)
    using namespace precious_stone;
   	StreamSource newSource{};
    ConvertCaesar convert{};
    StreamDestination newDestination{std::cout};
    BlackBox b{newSource, newDestination, convert};
    b.execut();

	ASSERT_PASS();
END_TEST

BEGIN_TEST(send_premitive_message)
    using namespace precious_stone;
   	StreamSource newSource{};

	std::stringstream stream;
    StreamDestination newDestination{stream};

    Message m = newSource.readMessege();
    newDestination.sendMessege(m);
    std::string s = stream.str();
	ASSERT_EQUAL(s, "zz");
END_TEST

BEGIN_TEST(send_premitive_message_cout)
    using namespace precious_stone;
   	StreamSource newSource{};
    StreamDestination newDestination{std::cout};
    Message m = newSource.readMessege();
    newDestination.sendMessege(m);

	ASSERT_EQUAL(m.get(), "zz");
END_TEST

BEGIN_TEST(Udp_message_to_consol)
    using namespace precious_stone;
   	UdpSource udpS(123, "172.17.0.1");
    
    StreamDestination newDestination{std::cout};

    Message m = udpS.readMessege();
    newDestination.sendMessege(m);

    ASSERT_EQUAL(m.get(), "zz");
END_TEST

BEGIN_TEST(console_input_convert_caesar)
    using namespace precious_stone;
   	StreamSource newSource{};
    StreamDestination newDestination{std::cout};
    ConvertCaesar convert{};
    Message m = newSource.readMessege();
    m = convert.messageEncoder(m);
    newDestination.sendMessege(m);

    ASSERT_EQUAL(m.get(), "zz");
END_TEST

BEGIN_TEST(console_input_convert_vowel)
    using namespace precious_stone;
   	StreamSource newSource{};
    StreamDestination newDestination{std::cout};
    ConvertVowel convert{};
    Message m = newSource.readMessege();
    m = convert.messageEncoder(m);
    newDestination.sendMessege(m);

    ASSERT_EQUAL(m.get(), "**z");
END_TEST

BEGIN_TEST(console_input_convert_ConvertCapitalize)
    using namespace precious_stone;
   	StreamSource newSource{};
    StreamDestination newDestination{std::cout};
    ConvertCapitalize convert{};
    Message m = newSource.readMessege();
    m = convert.messageEncoder(m);
    newDestination.sendMessege(m);

    ASSERT_EQUAL(m.get(), "**z");
END_TEST

BEGIN_TEST(send_message_from_file)
    using namespace precious_stone;
   	TextFileSource fileSource{"myFile.txx"};
	TextFileDestination fileDestination{"secFile.txx"};

    Message m = fileSource.readMessege();
    fileDestination.sendMessege(m);

	ASSERT_EQUAL(m.get(), "hello");
END_TEST

BEGIN_TEST(send_message_from_file_to_consol)
    using namespace precious_stone;
   	TextFileSource fileSource{"myFile.txx"};
	StreamDestination newDestination{std::cout};

    Message m = fileSource.readMessege();
    newDestination.sendMessege(m);

	ASSERT_EQUAL(m.get(), "hello");
END_TEST

TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
    TEST(black_box_consol_consol_caeser)
    // TEST(send_premitive_message)
    // TEST(send_premitive_message_cout)
    //TEST(console_input_convert_caesar)
    //TEST(console_input_convert_vowel)
    //TEST(console_input_convert_ConvertCapitalize)
    //TEST(Udp_message_to_consol)
    // TEST(send_message_from_file)
    // TEST(send_message_from_file_to_consol)
END_SUITE

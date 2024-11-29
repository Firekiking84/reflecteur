// ************************************************
// 21/11/2024 14:13:22
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		<gtest/gtest.h>

#include		"midiReader.hh"

TEST(VLQ_TEST, Test_read_write)
{
  ef::MidiReader	reader;
  char			tmp[256];
  uint32_t		input_number;
  uint32_t		output_number;
  int			ret;

  input_number = 300;
  ret = reader.write_vlq(input_number, tmp);
  EXPECT_EQ(ret, 2);
  ret = reader.read_vlq(tmp, &output_number);
  EXPECT_EQ(ret, 2);
  EXPECT_EQ(input_number, output_number);
}

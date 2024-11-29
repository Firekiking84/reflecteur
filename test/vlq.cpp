// ************************************************
// 21/11/2024 14:13:22
// Keryan HOUSSIN 
// Reflecteur
// ************************************************

#include		<gtest/gtest.h>
#include		<cstring>

#include		"midiReader.hh"

TEST(VLQ_TEST, Test_read_write)
{
  ef::MidiReader	reader;
  char			tmp[256];
  char			*cursor;
  uint32_t		input_number;
  uint32_t		output_number;
  int			ret;

  strcpy(tmp, "0123456789");
  cursor = tmp;
  input_number = 300;
  ret = reader.write_vlq(input_number, tmp);
  EXPECT_EQ(ret, 2);
  ret = reader.read_vlq(tmp, &output_number);
  EXPECT_EQ(ret, 2);
  EXPECT_EQ(input_number, output_number);
  cursor += ret;
  EXPECT_EQ(*cursor, '2');

  strcpy(tmp, "0123456789");
  cursor = tmp;
  input_number = 3;
  ret = reader.write_vlq(input_number, tmp);
  EXPECT_EQ(ret, 1);
  ret = reader.read_vlq(tmp, &output_number);
  EXPECT_EQ(ret, 1);
  EXPECT_EQ(input_number, output_number);
  cursor += ret;
  EXPECT_EQ(*cursor, '1');

  strcpy(tmp, "0123456789");
  cursor = tmp;
  input_number = 31234;
  ret = reader.write_vlq(input_number, tmp);
  EXPECT_EQ(ret, 3);
  ret = reader.read_vlq(tmp, &output_number);
  EXPECT_EQ(ret, 3);
  EXPECT_EQ(input_number, output_number);
  cursor += ret;
  EXPECT_EQ(*cursor, '3');

  strcpy(tmp, "0123456789");
  cursor = tmp;
  input_number = 25000000;
  ret = reader.write_vlq(input_number, tmp);
  EXPECT_EQ(ret, 4);
  ret = reader.read_vlq(tmp, &output_number);
  EXPECT_EQ(ret, 4);
  EXPECT_EQ(input_number, output_number);
  cursor += ret;
  EXPECT_EQ(*cursor, '4');
}

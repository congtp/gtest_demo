#include <gtest/gtest.h>
#include <cstdio>

class sprintfFixture : public ::testing::Test
{
protected:
    void SetUp() override
    {
        memset(this->output_, 170, sizeof(this->output_));
        this->expected_ = "";
    }

    void TearDown() override 
    {

    }

private:
    char output_[100];
    const char *expected_;

public:

    char *getOutput(void) const
    {
        return (char*)this->output_;
    }

    void expect(const char *s)
    {
        expected_ = s;
    }

    void given(int charsWritten)
    {

        ASSERT_EQ(strlen(this->expected_), charsWritten);

        ASSERT_STREQ(this->expected_, this->output_);

        ASSERT_EQ((char)0xaa, this->output_[strlen(this->expected_) + 1]);
    }

};


TEST_F(sprintfFixture, NoFormatOperation)
{
    // SetUp()
    // Do the thing
    this->expect("hey");
    this->given(sprintf(this->getOutput(), "hey"));
    // TearDown()
}

TEST_F(sprintfFixture, InsertString)
{
    // SetUp()
    // Do the thing
    expect("Hello World\n");
    given(sprintf(this->getOutput(), "Hello %s\n", "World"));
    // TearDown()
}
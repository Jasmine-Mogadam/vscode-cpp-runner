#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Cart.h"
#include "Item.h"
#include "ItemService.h"
#include <vector>
#include <iostream>

using ::testing::_;
using ::testing::Return;

// 5. Create a “mock” object for ItemService.h
class MockItemService : public ItemService
{
public:
    MOCK_METHOD(double, getPrice, (Item & item), (override));
};

// 7. Use SetUp() and TearDown() in TestFixture
class CartTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        std::cout << "SetUp: Preparing the test environment..." << std::endl;
    }

    void TearDown() override
    {
        std::cout << "TearDown: Cleaning up after the test..." << std::endl;
    }
};

TEST_F(CartTest, GetCartTotalAmount)
{
    // 4. Create items and add items to the Cart
    Item SDcard("1", "SDcard", 1);
    Item LEDlight("2", "LEDlight", 1);
    Item DashCam("3", "DashCam", 2);
    std::vector<Item> items = {SDcard, LEDlight, DashCam};

    // YOUR TASK:
    // - Instantiate MockItemService
    // - Set expectations (make it return a price for each item)
    // - Instantiate Cart, set the service and items
    // - 6. Check that getCartTotalAmount method returns correct output (use “EXPECT_EQ”)

    // Example expectation:
    // EXPECT_CALL(mockService, getPrice(_)).WillRepeatedly(Return(10.0));
}

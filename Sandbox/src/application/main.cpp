#include "math/math.h"
#include "logging/logger.h"

int main()
{
    int result = jumi::add(1, 3);
    JUMI_INFO("{}", result);

    return 0;
}

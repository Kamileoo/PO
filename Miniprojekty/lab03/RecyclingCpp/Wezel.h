#ifndef WEZEL_H
#define WEZEL_H

#include <iostream>
#include <memory>

class Wezel {
public:
    ~Wezel();

    std::shared_ptr<Wezel> next;
    std::weak_ptr<Wezel> weakNext;
};
#endif /* !WEZEL_H */
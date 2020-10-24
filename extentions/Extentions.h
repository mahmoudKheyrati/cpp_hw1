#pragma once

template<typename Base, typename T>
inline bool instanceof(T *t) {
    return dynamic_cast<Base *>(t);
}
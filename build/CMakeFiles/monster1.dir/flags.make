# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# compile CXX with /usr/bin/c++
CXX_FLAGS = -std=gnu++11   -fPIC   -DLZMA_API_STATIC -DBOOST_IOSTREAMS_USE_BZIP2=1 -DBOOST_IOSTREAMS_USE_ZLIB=1 -DBOOST_IOSTREAMS_USE_LZMA=1 -DBOOST_IOSTREAMS_USE_ZSTD=1 -DFLAC__NO_DLL -DAL_LIBTYPE_STATIC -DSTB_TEXTEDIT_KEYTYPE=unsigned -DBOOST_ALL_NO_LIB=1 -std=gnu++11

CXX_DEFINES = -Dmonster1_EXPORTS

CXX_INCLUDES = -I/home/takoo/.conan/data/boost_asio/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/asio/include -I/home/takoo/.conan/data/sfml/2.5.1/bincrafters/stable/package/b863e2409bedf059ca0146ac54e6435d44ee1124/include -I/home/takoo/.conan/data/boost_coroutine/1.69.0/bincrafters/stable/package/3a126ad3c96cb43850c72e8d16858ee488064b51/coroutine/include -I/home/takoo/.conan/data/freetype/2.9.0/bincrafters/stable/package/3cdd93cd46fc07735d1b0d7f2860a82fac7a3053/include -I/home/takoo/.conan/data/freetype/2.9.0/bincrafters/stable/package/3cdd93cd46fc07735d1b0d7f2860a82fac7a3053/include/freetype2 -I/home/takoo/.conan/data/stb/20180214/conan/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/include -I/home/takoo/.conan/data/openal/1.19.0/bincrafters/stable/package/812e1deb664b70de9456fc54c225f826fbca36e7/include -I/home/takoo/.conan/data/openal/1.19.0/bincrafters/stable/package/812e1deb664b70de9456fc54c225f826fbca36e7/include/AL -I/home/takoo/.conan/data/flac/1.3.2/bincrafters/stable/package/ef227c7ca8be49f078e2c7c4a6cebbac879b693a/include -I/home/takoo/.conan/data/vorbis/1.3.6/bincrafters/stable/package/8d8cebdeda6ff46ba515968aa8b099a24769ca16/include -I/home/takoo/.conan/data/boost_context/1.69.0/bincrafters/stable/package/fdc3c109b752a0f02a0df154e7fd9582761316d2/context/include -I/home/takoo/.conan/data/libpng/1.6.34/bincrafters/stable/package/b781af3f476d0aa5070a0a35b544db7a3c193cc8/include -I/home/takoo/.conan/data/libalsa/1.1.5/conan/stable/package/bff9a7d5ab267a535181ec5b36392417340ff035/include -I/home/takoo/.conan/data/ogg/1.3.3/bincrafters/stable/package/d50a0d523d98c15bb147b18fa7d203887c38be8b/include -I/home/takoo/.conan/data/boost_cycle_group_c/1.69.0/bincrafters/stable/package/442696888164f2773dc55435aba4739641ba9940/date_time/include -I/home/takoo/.conan/data/boost_cycle_group_c/1.69.0/bincrafters/stable/package/442696888164f2773dc55435aba4739641ba9940/dynamic_bitset/include -I/home/takoo/.conan/data/boost_cycle_group_c/1.69.0/bincrafters/stable/package/442696888164f2773dc55435aba4739641ba9940/iostreams/include -I/home/takoo/.conan/data/boost_cycle_group_c/1.69.0/bincrafters/stable/package/442696888164f2773dc55435aba4739641ba9940/multiprecision/include -I/home/takoo/.conan/data/boost_cycle_group_c/1.69.0/bincrafters/stable/package/442696888164f2773dc55435aba4739641ba9940/random/include -I/home/takoo/.conan/data/boost_cycle_group_c/1.69.0/bincrafters/stable/package/442696888164f2773dc55435aba4739641ba9940/serialization/include -I/home/takoo/.conan/data/boost_cycle_group_c/1.69.0/bincrafters/stable/package/442696888164f2773dc55435aba4739641ba9940/spirit/include -I/home/takoo/.conan/data/boost_cycle_group_c/1.69.0/bincrafters/stable/package/442696888164f2773dc55435aba4739641ba9940/thread/include -I/home/takoo/.conan/data/boost_chrono/1.69.0/bincrafters/stable/package/ce35b0314e3ac4d3bef6c25d378f0ae50b74faee/chrono/include -I/home/takoo/.conan/data/boost_pool/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/pool/include -I/home/takoo/.conan/data/boost_endian/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/endian/include -I/home/takoo/.conan/data/boost_filesystem/1.69.0/bincrafters/stable/package/eae29f422477d86464fecbf40168da4935248cce/filesystem/include -I/home/takoo/.conan/data/boost_foreach/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/foreach/include -I/home/takoo/.conan/data/boost_locale/1.69.0/bincrafters/stable/package/e71e34ac7b5ccfea2103ad478158f6be7d1aabb6/locale/include -I/home/takoo/.conan/data/boost_phoenix/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/phoenix/include -I/home/takoo/.conan/data/boost_tokenizer/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/tokenizer/include -I/home/takoo/.conan/data/boost_tti/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/tti/include -I/home/takoo/.conan/data/boost_variant/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/variant/include -I/home/takoo/.conan/data/bzip2/1.0.6/conan/stable/package/b27e2b40bcb70be2e7d6f0e0c6e43e35c530f8d3/include -I/home/takoo/.conan/data/zlib/1.2.11/conan/stable/package/d50a0d523d98c15bb147b18fa7d203887c38be8b/include -I/home/takoo/.conan/data/lzma/5.2.4/bincrafters/stable/package/d50a0d523d98c15bb147b18fa7d203887c38be8b/include -I/home/takoo/.conan/data/zstd/1.3.5/bincrafters/stable/package/d50a0d523d98c15bb147b18fa7d203887c38be8b/include -I/home/takoo/.conan/data/boost_ratio/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/ratio/include -I/home/takoo/.conan/data/boost_system/1.69.0/bincrafters/stable/package/663b6ae87778ab67e3abf1b0e1db7bbd5c0a1794/system/include -I/home/takoo/.conan/data/boost_io/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/io/include -I/home/takoo/.conan/data/boost_cycle_group_b/1.69.0/bincrafters/stable/package/7e744d95367a14dd340f0ad8d43c5e33b4a844aa/lexical_cast/include -I/home/takoo/.conan/data/boost_cycle_group_b/1.69.0/bincrafters/stable/package/7e744d95367a14dd340f0ad8d43c5e33b4a844aa/math/include -I/home/takoo/.conan/data/boost_proto/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/proto/include -I/home/takoo/.conan/data/boost_rational/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/rational/include -I/home/takoo/.conan/data/boost_winapi/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/winapi/include -I/home/takoo/.conan/data/boost_atomic/1.69.0/bincrafters/stable/package/80d4553e807857a762eb0f64781d0625c1b0ad72/atomic/include -I/home/takoo/.conan/data/boost_lambda/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/lambda/include -I/home/takoo/.conan/data/boost_cycle_group_a/1.69.0/bincrafters/stable/package/c78db0d0ae21a5cfa9c6ecc4cc08cec1221ba444/algorithm/include -I/home/takoo/.conan/data/boost_cycle_group_a/1.69.0/bincrafters/stable/package/c78db0d0ae21a5cfa9c6ecc4cc08cec1221ba444/range/include -I/home/takoo/.conan/data/boost_array/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/array/include -I/home/takoo/.conan/data/boost_exception/1.69.0/bincrafters/stable/package/a2b0f38cd477002de46eaedcab7fafd540d3be0a/exception/include -I/home/takoo/.conan/data/boost_function/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/function/include -I/home/takoo/.conan/data/boost_numeric_conversion/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/numeric_conversion/include -I/home/takoo/.conan/data/boost_regex/1.69.0/bincrafters/stable/package/02dfd2e024018d0d9493b40e3cb73694b7182084/regex/include -I/home/takoo/.conan/data/boost_unordered/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/unordered/include -I/home/takoo/.conan/data/boost_bind/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/bind/include -I/home/takoo/.conan/data/boost_type_index/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/type_index/include -I/home/takoo/.conan/data/boost_iterator/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/iterator/include -I/home/takoo/.conan/data/boost_container/1.69.0/bincrafters/stable/package/14cb647d789b7ccacc6b582166c87fbb1aeb68ca/container/include -I/home/takoo/.conan/data/boost_concept_check/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/concept_check/include -I/home/takoo/.conan/data/boost_conversion/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/conversion/include -I/home/takoo/.conan/data/boost_fusion/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/fusion/include -I/home/takoo/.conan/data/boost_optional/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/optional/include -I/home/takoo/.conan/data/boost_intrusive/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/intrusive/include -I/home/takoo/.conan/data/boost_typeof/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/typeof/include -I/home/takoo/.conan/data/boost_smart_ptr/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/smart_ptr/include -I/home/takoo/.conan/data/boost_tuple/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/tuple/include -I/home/takoo/.conan/data/boost_function_types/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/function_types/include -I/home/takoo/.conan/data/boost_move/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/move/include -I/home/takoo/.conan/data/boost_mpl/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/mpl/include -I/home/takoo/.conan/data/boost_predef/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/predef/include -I/home/takoo/.conan/data/boost_utility/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/utility/include -I/home/takoo/.conan/data/boost_throw_exception/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/throw_exception/include -I/home/takoo/.conan/data/boost_container_hash/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/container_hash/include -I/home/takoo/.conan/data/boost_integer/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/integer/include -I/home/takoo/.conan/data/boost_detail/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/detail/include -I/home/takoo/.conan/data/boost_core/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/core/include -I/home/takoo/.conan/data/boost_preprocessor/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/preprocessor/include -I/home/takoo/.conan/data/boost_type_traits/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/type_traits/include -I/home/takoo/.conan/data/boost_assert/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/assert/include -I/home/takoo/.conan/data/boost_static_assert/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/static_assert/include -I/home/takoo/.conan/data/boost_config/1.69.0/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/config/include -I/home/takoo/on/CPP_rtype_2019/client/include -I/home/takoo/on/CPP_rtype_2019/client/include/network/asio -I/home/takoo/on/CPP_rtype_2019/client/include/network/abstraction -I/home/takoo/on/CPP_rtype_2019/client/include/graphics -I/home/takoo/on/CPP_rtype_2019/client/include/graphics/SFML -I/home/takoo/on/CPP_rtype_2019/client/include/graphics/Interfaces -I/home/takoo/on/CPP_rtype_2019/server/include -I/home/takoo/on/CPP_rtype_2019/server/include/network -I/home/takoo/on/CPP_rtype_2019/server/include/network/asio -I/home/takoo/on/CPP_rtype_2019/server/include/network/abstraction -I/home/takoo/on/CPP_rtype_2019/ECS/include -I/home/takoo/on/CPP_rtype_2019/ECS/include/BasicEngine -I/home/takoo/on/CPP_rtype_2019/lib/include -I/home/takoo/on/CPP_rtype_2019/ECS/include/system -I/home/takoo/on/CPP_rtype_2019/include 


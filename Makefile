.PHONY: all
all: format test build debug static-test clean doc

.PHONY: docker-all
docker-all: docker-build docker-run

.PHONY: docker-build
docker-build:
	docker build -t cpp-design-pattern .

.PHONY: docker-run
docker-run:
	docker run -it --rm -v ${PWD}:/develop cpp-design-pattern

.PHONY: format
format:
	find src -iname *.h -o -iname *.cpp | xargs clang-format -i
	find test -iname *.h -o -iname *.cpp | xargs clang-format -i

.PHONY: build
build:
	mkdir -p build
	cd build && \
	cmake -DOPTION_BUILD_DOCS=OFF .. && \
	make

.PHONY: test
test:
	mkdir -p build
	cd build && \
	cmake -DOPTION_BUILD_DOCS=OFF -DOPTION_TEST_ALL=OFF ..&& \
	make &&\
	test/CPP_DESIGN_PATTERN_TEST

.PHONY: test-all
test-all:
	mkdir -p build
	cd build && \
	cmake -DOPTION_BUILD_DOCS=OFF -DOPTION_TEST_ALL=ON ..&& \
	make &&\
	test/CPP_DESIGN_PATTERN_TEST

.PHONY: test-all-report
test-all-report:
	mkdir -p build
	cd build && \
	cmake -DOPTION_BUILD_DOCS=OFF -DOPTION_TEST_ALL=ON ..&& \
	make &&\
	test/CPP_DESIGN_PATTERN_TEST --gtest_output=xml:test_result.xml

.PHONY: debug
debug:
	mkdir -p build
	cd build && \
	cmake -DCMAKE_BUILD_TYPE=debug -DCMAKE_CXX_CLANG_TIDY="clang-tidy;-checks=-*,google-readability-casting;-fix;-fix-errors;" .. &&\
	make

.PHONY: static-test
static-test:
	mkdir -p build/static-test
	cppcheck --cppcheck-build-dir=build/static-tesst src

.PHONY: clean
clean:
	rm -rf build

.PHONY: doc
doc:
	mkdir -p build
	cd build && \
	cmake -DOPTION_BUILD_DOCS=ON .. && \
	make docs
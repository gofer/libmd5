TEST_DIRS = test01 test02 test03 test04

.PHONY: all test distclean

all:
	@for dir in $(TEST_DIRS); do cd $${dir}; make; ret=$$?; if [ $${ret} -ne 0 ]; then exit $${ret}; fi; cd ..; done

test:
	@for dir in $(TEST_DIRS); do cd $${dir}; make test; ret=$$?; if [ $${ret} -ne 0 ]; then exit $${ret}; fi; cd ..; done

test-static:
	@for dir in $(TEST_DIRS); do cd $${dir}; make test-static; ret=$$?; if [ $${ret} -ne 0 ]; then exit $${ret}; fi; cd ..; done

test-shared:
	@for dir in $(TEST_DIRS); do cd $${dir}; make test-shared; ret=$$?; if [ $${ret} -ne 0 ]; then exit $${ret}; fi; cd ..; done

clean:
	@for dir in $(TEST_DIRS); do cd $${dir}; make clean; cd ..; done

distclean:
	@for dir in $(TEST_DIRS); do cd $${dir}; make distclean; cd ..; done

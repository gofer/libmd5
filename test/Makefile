TEST_DIRS = test01 test02 test03 test04

.PHONY: all check clean distclean

all:
	@for dir in $(TEST_DIRS); do cd $${dir}; make; ret=$$?; if [ $${ret} -ne 0 ]; then exit $${ret}; fi; cd ..; done

check:
	@for dir in $(TEST_DIRS); do cd $${dir}; make check; ret=$$?; if [ $${ret} -ne 0 ]; then exit $${ret}; fi; cd ..; done

clean:
	@for dir in $(TEST_DIRS); do cd $${dir}; makei clean; cd ..; done

distclean:
	@for dir in $(TEST_DIRS); do cd $${dir}; make distclean; cd ..; done

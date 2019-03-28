src=$(shell find . -name "*.dot")
images=$(src:%.dot=%.svg)

all:$(images)

%.svg:%.dot
	dot -T eps -o $@ $<

.PHONY:clean
clean:
	@rm $(images)

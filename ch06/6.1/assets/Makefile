src=$(shell find . -name "*.dot")
images=$(src:%.dot=%.svg)

all:$(images)

%.svg:%.dot
	dot -T svg -o $@ $<

.PHONY:clean
clean:
	@rm $(images)

TEX = $(wildcard */sections/*.tex *.tex */*.tex */tables/*.tex)
BIB = $(wildcard bib/*.bib)

.PHONY: list
list:
	@$(MAKE) -pRrq -f $(lastword $(MAKEFILE_LIST)) : 2>/dev/null | awk -v RS= -F: '/^# File/,/^# Finished Make data base/ {if ($$1 !~ "^[#.]") {print $$1}}' | sort | egrep -v -e '^[^[:alnum:]]' -e '^$@$$'

clean:
	rm -f *.aux *.dvi *.log *.bbl /*.pdf *~ *.out *.blg *.nav *.toc *.snm *.fdb_latexmk *.fls *.synctex.gz *.xmpi *.xml *.bcf
	rm -f */*.aux */*.dvi */*.log */*.bbl */*~ */*.out */*.blg */*/*~
	rm -fR auto_commit_fig
	rm -fR auto_fig
	rm -fR *.tgz

.PRECIOUS: auto_fig/res.txt


#%.pdf: %.tex auto_fig/res.txt $(TEX) $(BIB)
 %.pdf: %.tex $(TEX) $(BIB)
	latexmk --shell-escape -pdf -pv $*				#If fails to compile, try removing --shell-escape argument. Is required on MacOS. 

# These targets should remain in sync (e.g., if you fix one, do the same for the other).  Except for the .tgz target should have all the bib files but the arxiv target should have the bbl file ($<)
%.tgz: %.bbl
	tar cvfz $@ Makefile style/*.sty style/*.bst style/*.cls $(<:.bbl=.tex) bib/*.bib style/*.tex figures/* auto_fig/* sections/*.tex

%.arxiv.tgz: %.bbl
	tar cvfz $@ Makefile $< style/*.sty style/*.bst style/*.cls $(<:.bbl=.tex) style/*.tex figures/* auto_fig/* sections/*.tex

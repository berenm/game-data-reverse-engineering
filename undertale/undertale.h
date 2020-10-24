#ifndef UNDERTALE_H_
#define UNDERTALE_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include <kaitai/kaitaistruct.h>
#include <kaitai/kaitaistream.h>

#include <stdint.h>
#include <vector>
#include <sstream>

class undertale_t : public kaitai::kstruct {

public:
    class tmln_t;
    class dafl_t;
    class path_t;
    class gen8_t;
    class optn_t;
    class agrp_t;
    class bgnd_t;
    class txtr_t;
    class tpag_t;
    class string_t;
    class code_t;
    class strg_data_t;
    class scpt_t;
    class font_t;
    class sprt_t;
    class audo_t;
    class vari_t;
    class extn_t;
    class strg_t;
    class func_t;
    class room_t;
    class form_t;
    class objt_t;
    class sond_t;
    class shdr_t;

    undertale_t(kaitai::kstream* p_io, kaitai::kstruct* p_parent = 0, undertale_t* p_root = 0);
    ~undertale_t();

    class tmln_t : public kaitai::kstruct {

    public:

        tmln_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~tmln_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class dafl_t : public kaitai::kstruct {

    public:

        dafl_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~dafl_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class path_t : public kaitai::kstruct {

    public:

        path_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~path_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class gen8_t : public kaitai::kstruct {

    public:

        gen8_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~gen8_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class optn_t : public kaitai::kstruct {

    public:

        optn_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~optn_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class agrp_t : public kaitai::kstruct {

    public:

        agrp_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~agrp_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class bgnd_t : public kaitai::kstruct {

    public:

        bgnd_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~bgnd_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class txtr_t : public kaitai::kstruct {

    public:

        txtr_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~txtr_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class tpag_t : public kaitai::kstruct {

    public:

        tpag_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~tpag_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class string_t : public kaitai::kstruct {

    public:

        string_t(kaitai::kstream* p_io, undertale_t::strg_data_t* p_parent = 0, undertale_t* p_root = 0);
        ~string_t();

    private:
        uint32_t m_size;
        std::string m_string;
        undertale_t* m__root;
        undertale_t::strg_data_t* m__parent;

    public:
        uint32_t size() const { return m_size; }
        std::string string() const { return m_string; }
        undertale_t* _root() const { return m__root; }
        undertale_t::strg_data_t* _parent() const { return m__parent; }
    };

    class code_t : public kaitai::kstruct {

    public:

        code_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~code_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class strg_data_t : public kaitai::kstruct {

    public:

        strg_data_t(kaitai::kstream* p_io, undertale_t::strg_t* p_parent = 0, undertale_t* p_root = 0);
        ~strg_data_t();

    private:
        uint32_t m_count;
        std::vector<uint32_t>* m_offsets;
        std::vector<string_t*>* m_strings;
        undertale_t* m__root;
        undertale_t::strg_t* m__parent;

    public:
        uint32_t count() const { return m_count; }
        std::vector<uint32_t>* offsets() const { return m_offsets; }
        std::vector<string_t*>* strings() const { return m_strings; }
        undertale_t* _root() const { return m__root; }
        undertale_t::strg_t* _parent() const { return m__parent; }
    };

    class scpt_t : public kaitai::kstruct {

    public:

        scpt_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~scpt_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class font_t : public kaitai::kstruct {

    public:

        font_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~font_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class sprt_t : public kaitai::kstruct {

    public:

        sprt_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~sprt_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class audo_t : public kaitai::kstruct {

    public:

        audo_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~audo_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class vari_t : public kaitai::kstruct {

    public:

        vari_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~vari_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class extn_t : public kaitai::kstruct {

    public:

        extn_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~extn_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class strg_t : public kaitai::kstruct {

    public:

        strg_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~strg_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        strg_data_t* m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;
        std::string m__raw_data;
        kaitai::kstream* m__io__raw_data;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        strg_data_t* data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
        std::string _raw_data() const { return m__raw_data; }
        kaitai::kstream* _io__raw_data() const { return m__io__raw_data; }
    };

    class func_t : public kaitai::kstruct {

    public:

        func_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~func_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class room_t : public kaitai::kstruct {

    public:

        room_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~room_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class form_t : public kaitai::kstruct {

    public:

        form_t(kaitai::kstream* p_io, undertale_t* p_parent = 0, undertale_t* p_root = 0);
        ~form_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        gen8_t* m_gen8;
        optn_t* m_optn;
        extn_t* m_extn;
        sond_t* m_sond;
        agrp_t* m_agrp;
        sprt_t* m_sprt;
        bgnd_t* m_bgnd;
        path_t* m_path;
        scpt_t* m_scpt;
        shdr_t* m_shdr;
        font_t* m_font;
        tmln_t* m_tmln;
        objt_t* m_objt;
        room_t* m_room;
        dafl_t* m_dafl;
        tpag_t* m_tpag;
        code_t* m_code;
        vari_t* m_vari;
        func_t* m_func;
        strg_t* m_strg;
        txtr_t* m_txtr;
        audo_t* m_audo;
        strg_t* m_l18n;
        bool n_l18n;

    public:
        bool _is_null_l18n() { l18n(); return n_l18n; };

    private:
        undertale_t* m__root;
        undertale_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        gen8_t* gen8() const { return m_gen8; }
        optn_t* optn() const { return m_optn; }
        extn_t* extn() const { return m_extn; }
        sond_t* sond() const { return m_sond; }
        agrp_t* agrp() const { return m_agrp; }
        sprt_t* sprt() const { return m_sprt; }
        bgnd_t* bgnd() const { return m_bgnd; }
        path_t* path() const { return m_path; }
        scpt_t* scpt() const { return m_scpt; }
        shdr_t* shdr() const { return m_shdr; }
        font_t* font() const { return m_font; }
        tmln_t* tmln() const { return m_tmln; }
        objt_t* objt() const { return m_objt; }
        room_t* room() const { return m_room; }
        dafl_t* dafl() const { return m_dafl; }
        tpag_t* tpag() const { return m_tpag; }
        code_t* code() const { return m_code; }
        vari_t* vari() const { return m_vari; }
        func_t* func() const { return m_func; }
        strg_t* strg() const { return m_strg; }
        txtr_t* txtr() const { return m_txtr; }
        audo_t* audo() const { return m_audo; }
        strg_t* l18n() const { return m_l18n; }
        undertale_t* _root() const { return m__root; }
        undertale_t* _parent() const { return m__parent; }
    };

    class objt_t : public kaitai::kstruct {

    public:

        objt_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~objt_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class sond_t : public kaitai::kstruct {

    public:

        sond_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~sond_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

    class shdr_t : public kaitai::kstruct {

    public:

        shdr_t(kaitai::kstream* p_io, undertale_t::form_t* p_parent = 0, undertale_t* p_root = 0);
        ~shdr_t();

    private:
        std::string m_magic;
        uint32_t m_size;
        std::string m_data;
        undertale_t* m__root;
        undertale_t::form_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint32_t size() const { return m_size; }
        std::string data() const { return m_data; }
        undertale_t* _root() const { return m__root; }
        undertale_t::form_t* _parent() const { return m__parent; }
    };

private:
    form_t* m_form;
    undertale_t* m__root;
    kaitai::kstruct* m__parent;

public:
    form_t* form() const { return m_form; }
    undertale_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // UNDERTALE_H_

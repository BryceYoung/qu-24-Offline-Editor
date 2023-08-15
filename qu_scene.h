#ifndef QU_SCENE_H_
#define QU_SCENE_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"

#include <stdint.h>
#include <vector>
#include <iostream>
#include <fstream>

#if KAITAI_STRUCT_VERSION < 7000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.7 or later is required"
#endif

class qu_scene_t : public kaitai::kstruct {

public:
    class channel_entry_t;
    class routing_entry_t;
    class fx_rack_entry_t;
    class section_end_t;
    class mutegroup_t;
    class dca_t;
    class amm_t;
    class qu_control_tab_t;
    class header_t;
    class softkey_t;
    class qu_control_control_t;

    kaitai::kstream* Write(std::string fileName);
    qu_scene_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, qu_scene_t* p__root = 0);

private:
    void _read();

public:
    ~qu_scene_t();

    class channel_entry_t : public kaitai::kstruct {

    public:
        class delay_t;
        class gate_t;
        class compressor_t;
        class ducker_t;
        class hpf_t;
        class peq_setting_t;
        class peq_t;
        class geq_t;

        bool Write(kaitai::kstream* p__io);

        channel_entry_t(kaitai::kstream* p__io, qu_scene_t* p__parent = 0, qu_scene_t* p__root = 0);

    private:
        void _read();

    public:
        ~channel_entry_t();

        class delay_t : public kaitai::kstruct {

        public:
            bool Write(kaitai::kstream* p__io);
            delay_t(kaitai::kstream* p__io, qu_scene_t::channel_entry_t* p__parent = 0, qu_scene_t* p__root = 0);

        private:
            void _read();

        public:
            ~delay_t();

        private:
            uint16_t m_time;
            uint8_t m_on_off;
            qu_scene_t* m__root;
            qu_scene_t::channel_entry_t* m__parent;

        public:
            uint16_t time() const { return m_time; }
            uint8_t on_off() const { return m_on_off; }
            qu_scene_t* _root() const { return m__root; }
            qu_scene_t::channel_entry_t* _parent() const { return m__parent; }
        };

        class gate_t : public kaitai::kstruct {

        public:
            bool Write(kaitai::kstream* p__io);
            gate_t(kaitai::kstream* p__io, qu_scene_t::channel_entry_t* p__parent = 0, qu_scene_t* p__root = 0);

        private:
            void _read();

        public:
            ~gate_t();

        private:
            uint16_t m_attack;
            uint16_t m_release;
            uint16_t m_hold;
            uint16_t m_threshold;
            uint16_t m_depth;
            uint8_t m_in_out;
            qu_scene_t* m__root;
            qu_scene_t::channel_entry_t* m__parent;

        public:
            uint16_t attack() const { return m_attack; }
            uint16_t release() const { return m_release; }
            uint16_t hold() const { return m_hold; }
            uint16_t threshold() const { return m_threshold; }
            uint16_t depth() const { return m_depth; }
            uint8_t in_out() const { return m_in_out; }
            qu_scene_t* _root() const { return m__root; }
            qu_scene_t::channel_entry_t* _parent() const { return m__parent; }
        };

        class compressor_t : public kaitai::kstruct {

        public:
            bool Write(kaitai::kstream* p__io);
            compressor_t(kaitai::kstream* p__io, qu_scene_t::channel_entry_t* p__parent = 0, qu_scene_t* p__root = 0);

        private:
            void _read();

        public:
            ~compressor_t();

        private:
            uint16_t m_attack;
            uint16_t m_release;
            uint16_t m_knee;
            uint16_t m_ratio;
            uint16_t m_threshold;
            uint16_t m_gain;
            uint8_t m_type;
            uint8_t m_in_out;
            qu_scene_t* m__root;
            qu_scene_t::channel_entry_t* m__parent;

        public:
            uint16_t attack() const { return m_attack; }
            uint16_t release() const { return m_release; }
            uint16_t knee() const { return m_knee; }
            uint16_t ratio() const { return m_ratio; }
            uint16_t threshold() const { return m_threshold; }
            uint16_t gain() const { return m_gain; }
            uint8_t type() const { return m_type; }
            uint8_t in_out() const { return m_in_out; }
            qu_scene_t* _root() const { return m__root; }
            qu_scene_t::channel_entry_t* _parent() const { return m__parent; }
        };

        class ducker_t : public kaitai::kstruct {

        public:
            bool Write(kaitai::kstream* p__io);
            ducker_t(kaitai::kstream* p__io, qu_scene_t::channel_entry_t* p__parent = 0, qu_scene_t* p__root = 0);

        private:
            void _read();

        public:
            ~ducker_t();

        private:
            uint16_t m_attack;
            uint16_t m_release;
            uint16_t m_hold;
            uint16_t m_threshold;
            uint16_t m_depth;
            uint8_t m_on_off;
            uint8_t m_trigger_input;
            uint8_t m_single_gang;
            std::string m_unk3;
            uint8_t m_insert;
            qu_scene_t* m__root;
            qu_scene_t::channel_entry_t* m__parent;

        public:
            uint16_t attack() const { return m_attack; }
            uint16_t release() const { return m_release; }
            uint16_t hold() const { return m_hold; }
            uint16_t threshold() const { return m_threshold; }
            uint16_t depth() const { return m_depth; }
            uint8_t on_off() const { return m_on_off; }
            uint8_t trigger_input() const { return m_trigger_input; }
            uint8_t single_gang() const { return m_single_gang; }
            std::string unk3() const { return m_unk3; }
            uint8_t insert() const { return m_insert; }
            qu_scene_t* _root() const { return m__root; }
            qu_scene_t::channel_entry_t* _parent() const { return m__parent; }
        };

        class hpf_t : public kaitai::kstruct {

        public:
            bool Write(kaitai::kstream* p__io);
            hpf_t(kaitai::kstream* p__io, qu_scene_t::channel_entry_t* p__parent = 0, qu_scene_t* p__root = 0);

        private:
            void _read();

        public:
            ~hpf_t();

        private:
            uint16_t m_frequency;
            uint8_t m_in_out;
            qu_scene_t* m__root;
            qu_scene_t::channel_entry_t* m__parent;

        public:
            uint16_t frequency() const { return m_frequency; }
            uint8_t in_out() const { return m_in_out; }
            qu_scene_t* _root() const { return m__root; }
            qu_scene_t::channel_entry_t* _parent() const { return m__parent; }
        };

        class peq_setting_t : public kaitai::kstruct {

        public:
            bool Write(kaitai::kstream* p__io);
            peq_setting_t(kaitai::kstream* p__io, qu_scene_t::channel_entry_t::peq_t* p__parent = 0, qu_scene_t* p__root = 0);

        private:
            void _read();

        public:
            ~peq_setting_t();

        private:
            uint16_t m_gain;
            uint16_t m_frequency;
            uint16_t m_width;
            qu_scene_t* m__root;
            qu_scene_t::channel_entry_t::peq_t* m__parent;

        public:
            uint16_t gain() const { return m_gain; }
            uint16_t frequency() const { return m_frequency; }
            uint16_t width() const { return m_width; }
            qu_scene_t* _root() const { return m__root; }
            qu_scene_t::channel_entry_t::peq_t* _parent() const { return m__parent; }
        };

        class peq_t : public kaitai::kstruct {

        public:
            bool Write(kaitai::kstream* p__io);
            peq_t(kaitai::kstream* p__io, qu_scene_t::channel_entry_t* p__parent = 0, qu_scene_t* p__root = 0);

        private:
            void _read();

        public:
            ~peq_t();

        private:
            peq_setting_t* m_lf;
            peq_setting_t* m_lm;
            peq_setting_t* m_hm;
            peq_setting_t* m_hf;
            uint8_t m_lf_shelf;
            uint8_t m_hf_shelf;
            uint8_t m_in_out;
            qu_scene_t* m__root;
            qu_scene_t::channel_entry_t* m__parent;

        public:
            peq_setting_t* lf() const { return m_lf; }
            peq_setting_t* lm() const { return m_lm; }
            peq_setting_t* hm() const { return m_hm; }
            peq_setting_t* hf() const { return m_hf; }
            uint8_t lf_shelf() const { return m_lf_shelf; }
            uint8_t hf_shelf() const { return m_hf_shelf; }
            uint8_t in_out() const { return m_in_out; }
            qu_scene_t* _root() const { return m__root; }
            qu_scene_t::channel_entry_t* _parent() const { return m__parent; }
        };

        class geq_t : public kaitai::kstruct {

        public:
            bool Write(kaitai::kstream* p__io);
            geq_t(kaitai::kstream* p__io, qu_scene_t::channel_entry_t* p__parent = 0, qu_scene_t* p__root = 0);

        private:
            void _read();

        public:
            ~geq_t();

        private:
            uint16_t m_band31;
            uint16_t m_band40;
            uint16_t m_band50;
            uint16_t m_band63;
            uint16_t m_band80;
            uint16_t m_band100;
            uint16_t m_band125;
            uint16_t m_band160;
            uint16_t m_band200;
            uint16_t m_band250;
            uint16_t m_band315;
            uint16_t m_band400;
            uint16_t m_band500;
            uint16_t m_band630;
            uint16_t m_band800;
            uint16_t m_band1k;
            uint16_t m_band1k25;
            uint16_t m_band1k6;
            uint16_t m_band2k;
            uint16_t m_band2k5;
            uint16_t m_band3k15;
            uint16_t m_band4k;
            uint16_t m_band5k;
            uint16_t m_band6k3;
            uint16_t m_band8k;
            uint16_t m_band10k;
            uint16_t m_band12k5;
            uint16_t m_band16k;
            qu_scene_t* m__root;
            qu_scene_t::channel_entry_t* m__parent;

        public:
            uint16_t band31() const { return m_band31; }
            uint16_t band40() const { return m_band40; }
            uint16_t band50() const { return m_band50; }
            uint16_t band63() const { return m_band63; }
            uint16_t band80() const { return m_band80; }
            uint16_t band100() const { return m_band100; }
            uint16_t band125() const { return m_band125; }
            uint16_t band160() const { return m_band160; }
            uint16_t band200() const { return m_band200; }
            uint16_t band250() const { return m_band250; }
            uint16_t band315() const { return m_band315; }
            uint16_t band400() const { return m_band400; }
            uint16_t band500() const { return m_band500; }
            uint16_t band630() const { return m_band630; }
            uint16_t band800() const { return m_band800; }
            uint16_t band1k() const { return m_band1k; }
            uint16_t band1k25() const { return m_band1k25; }
            uint16_t band1k6() const { return m_band1k6; }
            uint16_t band2k() const { return m_band2k; }
            uint16_t band2k5() const { return m_band2k5; }
            uint16_t band3k15() const { return m_band3k15; }
            uint16_t band4k() const { return m_band4k; }
            uint16_t band5k() const { return m_band5k; }
            uint16_t band6k3() const { return m_band6k3; }
            uint16_t band8k() const { return m_band8k; }
            uint16_t band10k() const { return m_band10k; }
            uint16_t band12k5() const { return m_band12k5; }
            uint16_t band16k() const { return m_band16k; }
            qu_scene_t* _root() const { return m__root; }
            qu_scene_t::channel_entry_t* _parent() const { return m__parent; }
        };

    private:
        peq_t* m_peq;
        std::string m_unk1;
        compressor_t* m_comp;
        gate_t* m_gate;
        std::string m_unk2;
        geq_t* m_geq;
        std::string m_unk3;
        hpf_t* m_hpf;
        std::string m_unk4;
        delay_t* m_delay;
        std::string m_unk5;
        uint16_t m_fader;
        uint16_t m_gain;
        uint16_t m_trim;
        uint8_t m_qu_drive_on_off;
        uint8_t m_phantom_on_off;
        uint8_t m_phase_flip_on_off;
        std::string m_unk6;
        uint8_t m_mute_on_off;
        uint8_t m_fx_insert_on_off;
        std::string m_unk7;
        uint8_t m_d_snake_on_off;
        uint16_t m_mutegroup_assignment;
        std::string m_unk8;
        uint8_t m_linked;
        std::string m_unk9;
        uint8_t m_preamp_linked;
        uint8_t m_dynamicssidechain_pan_fader_mute_linked;
        std::string m_unk10;
        uint16_t m_dsnake_gain;
        std::string m_unk11;
        uint8_t m_pad_20db_on_off;
        std::string m_name;
        std::string m_unk12;
        uint16_t m_dcagroup_assignment;
        ducker_t* m_ducker;
        uint8_t m_dsnake_input_number;
        std::string m_unk13;
        qu_scene_t* m__root;
        qu_scene_t* m__parent;

    public:
        peq_t* peq() const { return m_peq; }
        std::string unk1() const { return m_unk1; }
        compressor_t* comp() const { return m_comp; }
        gate_t* gate() const { return m_gate; }
        std::string unk2() const { return m_unk2; }
        geq_t* geq() const { return m_geq; }
        std::string unk3() const { return m_unk3; }
        hpf_t* hpf() const { return m_hpf; }
        std::string unk4() const { return m_unk4; }
        delay_t* delay() const { return m_delay; }
        std::string unk5() const { return m_unk5; }
        uint16_t getFader() const {return m_fader; }
        void setFader(uint16_t i_fader) {m_fader = i_fader;}
        uint16_t gain() const { return m_gain; }
        uint16_t trim() const { return m_trim; }
        uint8_t qu_drive_on_off() const { return m_qu_drive_on_off; }
        uint8_t phantom_on_off() const { return m_phantom_on_off; }
        uint8_t phase_flip_on_off() const { return m_phase_flip_on_off; }
        std::string unk6() const { return m_unk6; }
        enum Mute {UnMuted, Muted};
        enum Mute getMute() const {return (enum Mute)m_mute_on_off;}
        void setMute(enum Mute mute){m_mute_on_off = mute;}
        uint8_t fx_insert_on_off() const { return m_fx_insert_on_off; }
        std::string unk7() const { return m_unk7; }
        uint8_t d_snake_on_off() const { return m_d_snake_on_off; }
        uint16_t mutegroup_assignment() const { return m_mutegroup_assignment; }
        std::string unk8() const { return m_unk8; }
        uint8_t linked() const { return m_linked; }
        std::string unk9() const { return m_unk9; }
        uint8_t preamp_linked() const { return m_preamp_linked; }
        uint8_t dynamicssidechain_pan_fader_mute_linked() const { return m_dynamicssidechain_pan_fader_mute_linked; }
        std::string unk10() const { return m_unk10; }
        uint16_t dsnake_gain() const { return m_dsnake_gain; }
        std::string unk11() const { return m_unk11; }
        uint8_t pad_20db_on_off() const { return m_pad_20db_on_off; }
        std::string name() const { return m_name; }
        std::string unk12() const { return m_unk12; }
        uint16_t dcagroup_assignment() const { return m_dcagroup_assignment; }
        ducker_t* ducker() const { return m_ducker; }
        uint8_t dsnake_input_number() const { return m_dsnake_input_number; }
        std::string unk13() const { return m_unk13; }
        qu_scene_t* _root() const { return m__root; }
        qu_scene_t* _parent() const { return m__parent; }
    };

    class routing_entry_t : public kaitai::kstruct {

    public:
        class route_t;
        bool Write(kaitai::kstream* p__io);
        routing_entry_t(kaitai::kstream* p__io, qu_scene_t* p__parent = 0, qu_scene_t* p__root = 0);

    private:
        void _read();

    public:
        ~routing_entry_t();

        class route_t : public kaitai::kstruct {

        public:
            bool Write(kaitai::kstream* p__io);
            route_t(kaitai::kstream* p__io, qu_scene_t::routing_entry_t* p__parent = 0, qu_scene_t* p__root = 0);

        private:
            void _read();

        public:
            ~route_t();

        private:
            uint16_t m_gain;
            uint16_t m_pan;
            uint8_t m_pre_on_off;
            uint8_t m_on_off;
            std::string m_unused;
            qu_scene_t* m__root;
            qu_scene_t::routing_entry_t* m__parent;

        public:
            uint16_t gain() const { return m_gain; }
            uint16_t pan() const { return m_pan; }
            uint8_t pre_on_off() const { return m_pre_on_off; }
            uint8_t on_off() const { return m_on_off; }
            std::string unused() const { return m_unused; }
            qu_scene_t* _root() const { return m__root; }
            qu_scene_t::routing_entry_t* _parent() const { return m__parent; }
        };

    private:
        std::vector<route_t*>* m_mixes;
        route_t* m_lr;
        std::vector<route_t*>* m_groups;
        std::vector<route_t*>* m_matrices;
        std::vector<route_t*>* m_unk;
        std::vector<route_t*>* m_fx_sends;
        qu_scene_t* m__root;
        qu_scene_t* m__parent;

    public:
        std::vector<route_t*>* mixes() const { return m_mixes; }
        route_t* lr() const { return m_lr; }
        std::vector<route_t*>* groups() const { return m_groups; }
        std::vector<route_t*>* matrices() const { return m_matrices; }
        std::vector<route_t*>* unk() const { return m_unk; }
        std::vector<route_t*>* fx_sends() const { return m_fx_sends; }
        qu_scene_t* _root() const { return m__root; }
        qu_scene_t* _parent() const { return m__parent; }
    };

    class fx_rack_entry_t : public kaitai::kstruct {

    public:

        enum patch_t {
            PATCH_UNASSIGNED = 0,
            PATCH_INSERT = 1,
            PATCH_MIXRETURN = 2,
            PATCH_CHRETURN = 3
        };

        enum waveform_t {
            WAVEFORM_SINE = 32768,
            WAVEFORM_M = 32784,
            WAVEFORM_W = 32800,
            WAVEFORM_SAW = 32816,
            WAVEFORM_MANUAL = 32832
        };

        enum emulation_t {
            EMULATION_AMBIENT = 32784,
            EMULATION_VINTAGE = 32800,
            EMULATION_WILD = 32816
        };

        enum gatedverb_t {
            GATEDVERB_CLASSIC = 32768,
            GATEDVERB_PANNER = 32784,
            GATEDVERB_POWER = 32800
        };
        bool Write(kaitai::kstream* p__io);
        fx_rack_entry_t(kaitai::kstream* p__io, qu_scene_t* p__parent = 0, qu_scene_t* p__root = 0);

    private:
        void _read();

    public:
        ~fx_rack_entry_t();

    private:
        std::string m_unk_type;
        std::string m_name;
        uint16_t m_lfcut_rev_hpfin_delay_lfosinerect_chorus_flangetype_flanger_lfoselect_phaser_predelay_gatedverb;
        uint16_t m_hfcut_rev_lpfin_delay_monolfosplit_chorus_stereosplit_flanger_monosplit_phaser_type_gatedverb;
        uint16_t m_predelay_rev_fbfreq_delay_rate_chorus_speed_flanger_rate_phaser_frequency_symph_attack_gatedverb;
        uint16_t m_decaytime_rev_fbslope_delay_thickness_adt_depth_chorus_depth_flanger_depth_symph_hold_gatedverb;
        uint16_t m_hfdecay_rev_scatter_delay_wire_adt_monowide_chorus_stereospread_flanger_release_gatedverb;
        uint16_t m_hfslope_rev_tapleft_delay_delayseparation_adt_monomultivoice_chorus_regenerate_flanger_monostereowide_gatedverb;
        uint16_t m_diffusion_rev_link_delay_doublequadtrack_adt_diffusion_gatedverb;
        uint16_t m_size_rev_tapright_delay_speed_adt_mixresonance_phaser_locut_gatedverb;
        uint16_t m_shapedecaydelay_rev_feedback_delay_depth_adt_panspeed_chorus_hicut_gatedverb;
        uint16_t m_refdetail_rev_width_delay_pandepth_chorus;
        uint16_t m_echo1;
        uint16_t m_echo1level_rev_emulationtype_flanger;
        uint16_t m_echo2_rev_speedmanual_flanger_resonantstages_phaser;
        uint16_t m_echo2level_rev_phasingstages_phaser;
        uint16_t m_bodydiffusion_rev_depth_phaser;
        uint16_t m_taildiffusion_rev_offset_phaser;
        uint16_t m_moddepth;
        uint16_t m_modspeed;
        uint16_t m_lfdecay;
        uint16_t m_lfxover;
        uint16_t m_colour;
        uint16_t m_colourfreq;
        uint16_t m_reflevel;
        uint16_t m_decaylevel;
        patch_t m_patchtype;
        uint8_t m_patchinput;
        std::string m_unk_end;
        qu_scene_t* m__root;
        qu_scene_t* m__parent;

    public:
        std::string unk_type() const { return m_unk_type; }
        std::string name() const { return m_name; }
        uint16_t lfcut_rev_hpfin_delay_lfosinerect_chorus_flangetype_flanger_lfoselect_phaser_predelay_gatedverb() const { return m_lfcut_rev_hpfin_delay_lfosinerect_chorus_flangetype_flanger_lfoselect_phaser_predelay_gatedverb; }
        uint16_t hfcut_rev_lpfin_delay_monolfosplit_chorus_stereosplit_flanger_monosplit_phaser_type_gatedverb() const { return m_hfcut_rev_lpfin_delay_monolfosplit_chorus_stereosplit_flanger_monosplit_phaser_type_gatedverb; }
        uint16_t predelay_rev_fbfreq_delay_rate_chorus_speed_flanger_rate_phaser_frequency_symph_attack_gatedverb() const { return m_predelay_rev_fbfreq_delay_rate_chorus_speed_flanger_rate_phaser_frequency_symph_attack_gatedverb; }
        uint16_t decaytime_rev_fbslope_delay_thickness_adt_depth_chorus_depth_flanger_depth_symph_hold_gatedverb() const { return m_decaytime_rev_fbslope_delay_thickness_adt_depth_chorus_depth_flanger_depth_symph_hold_gatedverb; }
        uint16_t hfdecay_rev_scatter_delay_wire_adt_monowide_chorus_stereospread_flanger_release_gatedverb() const { return m_hfdecay_rev_scatter_delay_wire_adt_monowide_chorus_stereospread_flanger_release_gatedverb; }
        uint16_t hfslope_rev_tapleft_delay_delayseparation_adt_monomultivoice_chorus_regenerate_flanger_monostereowide_gatedverb() const { return m_hfslope_rev_tapleft_delay_delayseparation_adt_monomultivoice_chorus_regenerate_flanger_monostereowide_gatedverb; }
        uint16_t diffusion_rev_link_delay_doublequadtrack_adt_diffusion_gatedverb() const { return m_diffusion_rev_link_delay_doublequadtrack_adt_diffusion_gatedverb; }
        uint16_t size_rev_tapright_delay_speed_adt_mixresonance_phaser_locut_gatedverb() const { return m_size_rev_tapright_delay_speed_adt_mixresonance_phaser_locut_gatedverb; }
        uint16_t shapedecaydelay_rev_feedback_delay_depth_adt_panspeed_chorus_hicut_gatedverb() const { return m_shapedecaydelay_rev_feedback_delay_depth_adt_panspeed_chorus_hicut_gatedverb; }
        uint16_t refdetail_rev_width_delay_pandepth_chorus() const { return m_refdetail_rev_width_delay_pandepth_chorus; }
        uint16_t echo1() const { return m_echo1; }
        uint16_t echo1level_rev_emulationtype_flanger() const { return m_echo1level_rev_emulationtype_flanger; }
        uint16_t echo2_rev_speedmanual_flanger_resonantstages_phaser() const { return m_echo2_rev_speedmanual_flanger_resonantstages_phaser; }
        uint16_t echo2level_rev_phasingstages_phaser() const { return m_echo2level_rev_phasingstages_phaser; }
        uint16_t bodydiffusion_rev_depth_phaser() const { return m_bodydiffusion_rev_depth_phaser; }
        uint16_t taildiffusion_rev_offset_phaser() const { return m_taildiffusion_rev_offset_phaser; }
        uint16_t moddepth() const { return m_moddepth; }
        uint16_t modspeed() const { return m_modspeed; }
        uint16_t lfdecay() const { return m_lfdecay; }
        uint16_t lfxover() const { return m_lfxover; }
        uint16_t colour() const { return m_colour; }
        uint16_t colourfreq() const { return m_colourfreq; }
        uint16_t reflevel() const { return m_reflevel; }
        uint16_t decaylevel() const { return m_decaylevel; }
        patch_t patchtype() const { return m_patchtype; }
        uint8_t patchinput() const { return m_patchinput; }
        std::string unk_end() const { return m_unk_end; }
        qu_scene_t* _root() const { return m__root; }
        qu_scene_t* _parent() const { return m__parent; }
    };

    class section_end_t : public kaitai::kstruct {

    public:
        bool Write(kaitai::kstream* p__io);
        section_end_t(kaitai::kstream* p__io, qu_scene_t* p__parent = 0, qu_scene_t* p__root = 0);

    private:
        void _read();

    public:
        ~section_end_t();

    private:
        uint8_t m_number;
        std::string m_terminator;
        qu_scene_t* m__root;
        qu_scene_t* m__parent;

    public:
        uint8_t number() const { return m_number; }
        std::string terminator() const { return m_terminator; }
        qu_scene_t* _root() const { return m__root; }
        qu_scene_t* _parent() const { return m__parent; }
    };

    class mutegroup_t : public kaitai::kstruct {

    public:
        bool Write(kaitai::kstream* p__io);
        mutegroup_t(kaitai::kstream* p__io, qu_scene_t* p__parent = 0, qu_scene_t* p__root = 0);

    private:
        void _read();

    public:
        ~mutegroup_t();

    private:
        std::string m_name;
        std::string m_unk;
        qu_scene_t* m__root;
        qu_scene_t* m__parent;

    public:
        std::string name() const { return m_name; }
        std::string unk() const { return m_unk; }
        qu_scene_t* _root() const { return m__root; }
        qu_scene_t* _parent() const { return m__parent; }
    };

    class dca_t : public kaitai::kstruct {

    public:
        bool Write(kaitai::kstream* p__io);
        dca_t(kaitai::kstream* p__io, qu_scene_t* p__parent = 0, qu_scene_t* p__root = 0);

    private:
        void _read();

    public:
        ~dca_t();

    private:
        uint16_t m_level;
        std::string m_unk;
        std::string m_name;
        std::string m_unk2;
        qu_scene_t* m__root;
        qu_scene_t* m__parent;

    public:
        uint16_t level() const { return m_level; }
        std::string unk() const { return m_unk; }
        std::string name() const { return m_name; }
        std::string unk2() const { return m_unk2; }
        qu_scene_t* _root() const { return m__root; }
        qu_scene_t* _parent() const { return m__parent; }
    };

    class amm_t : public kaitai::kstruct {

    public:
        bool Write(kaitai::kstream* p__io);
        amm_t(kaitai::kstream* p__io, qu_scene_t* p__parent = 0, qu_scene_t* p__root = 0);

    private:
        void _read();

    public:
        ~amm_t();

    private:
        uint16_t m_lpfilter;
        uint16_t m_hpfilter;
        std::string m_unk;
        std::vector<uint16_t>* m_priorities;
        qu_scene_t* m__root;
        qu_scene_t* m__parent;

    public:
        uint16_t lpfilter() const { return m_lpfilter; }
        uint16_t hpfilter() const { return m_hpfilter; }
        std::string unk() const { return m_unk; }
        std::vector<uint16_t>* priorities() const { return m_priorities; }
        qu_scene_t* _root() const { return m__root; }
        qu_scene_t* _parent() const { return m__parent; }
    };

    class qu_control_tab_t : public kaitai::kstruct {

    public:
        bool Write(kaitai::kstream* p__io);
        qu_control_tab_t(kaitai::kstream* p__io, qu_scene_t* p__parent = 0, qu_scene_t* p__root = 0);

    private:
        void _read();

    public:
        ~qu_control_tab_t();

    private:
        std::vector<qu_control_control_t*>* m_controls;
        std::string m_name;
        std::vector<std::string>* m_unk;
        qu_scene_t* m__root;
        qu_scene_t* m__parent;

    public:
        std::vector<qu_control_control_t*>* controls() const { return m_controls; }
        std::string name() const { return m_name; }
        std::vector<std::string>* unk() const { return m_unk; }
        qu_scene_t* _root() const { return m__root; }
        qu_scene_t* _parent() const { return m__parent; }
    };

    class header_t : public kaitai::kstruct {

    public:
        class version_t;
        bool Write(kaitai::kstream* p__io);
        header_t(kaitai::kstream* p__io, qu_scene_t* p__parent = 0, qu_scene_t* p__root = 0);

    private:
        void _read();

    public:
        ~header_t();

        class version_t : public kaitai::kstruct {

        public:
            bool Write(kaitai::kstream* p__io);
            version_t(kaitai::kstream* p__io, qu_scene_t::header_t* p__parent = 0, qu_scene_t* p__root = 0);

        private:
            void _read();

        public:
            ~version_t();

        private:
            uint64_t m_major;
            bool m_const_true;
            uint8_t m_minor;
            uint16_t m_revision;
            qu_scene_t* m__root;
            qu_scene_t::header_t* m__parent;

        public:
            uint64_t major() const { return m_major; }
            bool const_true() const { return m_const_true; }
            uint8_t minor() const { return m_minor; }
            uint16_t revision() const { return m_revision; }
            qu_scene_t* _root() const { return m__root; }
            qu_scene_t::header_t* _parent() const { return m__parent; }
        };

    private:
        std::string m_magic;
        uint8_t m_id;
        version_t* m_version;
        std::string m_unk1;
        std::string m_name;
        std::string m_unk2;
        qu_scene_t* m__root;
        qu_scene_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        uint8_t id() const { return m_id; }
        version_t* version() const { return m_version; }
        std::string unk1() const { return m_unk1; }
        std::string name() const { return m_name; }
        std::string unk2() const { return m_unk2; }
        qu_scene_t* _root() const { return m__root; }
        qu_scene_t* _parent() const { return m__parent; }
    };

    class softkey_t : public kaitai::kstruct {

    public:
        bool Write(kaitai::kstream* p__io);
        softkey_t(kaitai::kstream* p__io, qu_scene_t* p__parent = 0, qu_scene_t* p__root = 0);

    private:
        void _read();

    public:
        ~softkey_t();

    private:
        uint8_t m_function;
        uint16_t m_target;
        qu_scene_t* m__root;
        qu_scene_t* m__parent;

    public:
        uint8_t function() const { return m_function; }
        uint16_t target() const { return m_target; }
        qu_scene_t* _root() const { return m__root; }
        qu_scene_t* _parent() const { return m__parent; }
    };

    class qu_control_control_t : public kaitai::kstruct {

    public:
        bool Write(kaitai::kstream* p__io);
        qu_control_control_t(kaitai::kstream* p__io, qu_scene_t::qu_control_tab_t* p__parent = 0, qu_scene_t* p__root = 0);

    private:
        void _read();

    public:
        ~qu_control_control_t();

    private:
        uint8_t m_type;
        uint8_t m_target;
        uint8_t m_destination;
        std::string m_unk;
        qu_scene_t* m__root;
        qu_scene_t::qu_control_tab_t* m__parent;

    public:
        uint8_t type() const { return m_type; }
        uint8_t target() const { return m_target; }
        uint8_t destination() const { return m_destination; }
        std::string unk() const { return m_unk; }
        qu_scene_t* _root() const { return m__root; }
        qu_scene_t::qu_control_tab_t* _parent() const { return m__parent; }
    };

private:
    header_t* m_header;
    section_end_t* m_header_end;
    std::vector<channel_entry_t*>* m_inputs;
    std::vector<channel_entry_t*>* m_stereo_inputs;
    std::vector<channel_entry_t*>* m_fx_returns;
    std::vector<channel_entry_t*>* m_mixes;
    channel_entry_t* m_lr;
    std::vector<channel_entry_t*>* m_groups;
    std::vector<channel_entry_t*>* m_matrices;
    std::vector<channel_entry_t*>* m_chan12;
    std::vector<channel_entry_t*>* m_fx_sends;
    channel_entry_t* m_chan3;
    section_end_t* m_channel_end;
    std::vector<fx_rack_entry_t*>* m_fx_rack;
    section_end_t* m_fx_rack_end;
    std::vector<routing_entry_t*>* m_routing;
    section_end_t* m_routing_end;
    std::string m_sect5;
    section_end_t* m_sect5_end;
    std::string m_sect6;
    section_end_t* m_sect6_end;
    uint8_t m_additive_pafl;
    std::string m_sect7;
    section_end_t* m_sect7_end;
    std::string m_sect8;
    section_end_t* m_sect8_end;
    uint8_t m_siggen_type;
    std::string m_sect9;
    section_end_t* m_sect9_end;
    std::vector<softkey_t*>* m_softkeys;
    section_end_t* m_softkeys_end;
    std::string m_unk1;
    std::vector<uint8_t>* m_usb_patch;
    std::vector<std::string>* m_unk2;
    std::string m_usb_insert_do;
    std::vector<std::string>* m_unk3;
    std::vector<uint8_t>* m_surface_patch;
    std::vector<std::string>* m_unk4;
    section_end_t* m_patching_end;
    std::string m_sect12unk1;
    uint8_t m_midi_daw_channel;
    std::string m_sect12unk2;
    std::vector<uint8_t>* m_dsnake_out_patching;
    std::vector<uint8_t>* m_dsnake_out_expander_patching;
    std::vector<uint8_t>* m_monitor_patching;
    std::string m_unk5;
    std::vector<dca_t*>* m_dcas;
    std::vector<dca_t*>* m_unused_dca;
    std::vector<mutegroup_t*>* m_mutegroups;
    std::string m_sect12unk3;
    std::vector<qu_control_tab_t*>* m_qucontroltabs;
    std::string m_sect12unk4;
    amm_t* m_amm;
    std::string m_sect12unk5;
    std::vector<uint16_t>* m_footswitches;
    std::vector<std::string>* m_sect12unk6;
    std::string m_sect12unk7;
    section_end_t* m_sect12_end;
    uint32_t m_crc;
    qu_scene_t* m__root;
    kaitai::kstruct* m__parent;

public:
    header_t* header() const { return m_header; }
    section_end_t* header_end() const { return m_header_end; }
    std::vector<channel_entry_t*>* inputs() const { return m_inputs; }
    std::vector<channel_entry_t*>* stereo_inputs() const { return m_stereo_inputs; }
    std::vector<channel_entry_t*>* fx_returns() const { return m_fx_returns; }
    std::vector<channel_entry_t*>* mixes() const { return m_mixes; }
    channel_entry_t* lr() const { return m_lr; }
    std::vector<channel_entry_t*>* groups() const { return m_groups; }
    std::vector<channel_entry_t*>* matrices() const { return m_matrices; }
    std::vector<channel_entry_t*>* chan12() const { return m_chan12; }
    std::vector<channel_entry_t*>* fx_sends() const { return m_fx_sends; }
    channel_entry_t* chan3() const { return m_chan3; }
    section_end_t* channel_end() const { return m_channel_end; }
    std::vector<fx_rack_entry_t*>* fx_rack() const { return m_fx_rack; }
    section_end_t* fx_rack_end() const { return m_fx_rack_end; }
    std::vector<routing_entry_t*>* routing() const { return m_routing; }
    section_end_t* routing_end() const { return m_routing_end; }
    std::string sect5() const { return m_sect5; }
    section_end_t* sect5_end() const { return m_sect5_end; }
    std::string sect6() const { return m_sect6; }
    section_end_t* sect6_end() const { return m_sect6_end; }
    uint8_t additive_pafl() const { return m_additive_pafl; }
    std::string sect7() const { return m_sect7; }
    section_end_t* sect7_end() const { return m_sect7_end; }
    std::string sect8() const { return m_sect8; }
    section_end_t* sect8_end() const { return m_sect8_end; }
    uint8_t siggen_type() const { return m_siggen_type; }
    std::string sect9() const { return m_sect9; }
    section_end_t* sect9_end() const { return m_sect9_end; }
    std::vector<softkey_t*>* softkeys() const { return m_softkeys; }
    section_end_t* softkeys_end() const { return m_softkeys_end; }
    std::string unk1() const { return m_unk1; }
    std::vector<uint8_t>* usb_patch() const { return m_usb_patch; }
    std::vector<std::string>* unk2() const { return m_unk2; }
    std::string usb_insert_do() const { return m_usb_insert_do; }
    std::vector<std::string>* unk3() const { return m_unk3; }
    std::vector<uint8_t>* surface_patch() const { return m_surface_patch; }
    std::vector<std::string>* unk4() const { return m_unk4; }
    section_end_t* patching_end() const { return m_patching_end; }
    std::string sect12unk1() const { return m_sect12unk1; }
    uint8_t midi_daw_channel() const { return m_midi_daw_channel; }
    std::string sect12unk2() const { return m_sect12unk2; }
    std::vector<uint8_t>* dsnake_out_patching() const { return m_dsnake_out_patching; }
    std::vector<uint8_t>* dsnake_out_expander_patching() const { return m_dsnake_out_expander_patching; }
    std::vector<uint8_t>* monitor_patching() const { return m_monitor_patching; }
    std::string unk5() const { return m_unk5; }
    std::vector<dca_t*>* dcas() const { return m_dcas; }
    std::vector<dca_t*>* unused_dca() const { return m_unused_dca; }
    std::vector<mutegroup_t*>* mutegroups() const { return m_mutegroups; }
    std::string sect12unk3() const { return m_sect12unk3; }
    std::vector<qu_control_tab_t*>* qucontroltabs() const { return m_qucontroltabs; }
    std::string sect12unk4() const { return m_sect12unk4; }
    amm_t* amm() const { return m_amm; }
    std::string sect12unk5() const { return m_sect12unk5; }
    std::vector<uint16_t>* footswitches() const { return m_footswitches; }
    std::vector<std::string>* sect12unk6() const { return m_sect12unk6; }
    std::string sect12unk7() const { return m_sect12unk7; }
    section_end_t* sect12_end() const { return m_sect12_end; }
    uint32_t makeCrc(kaitai::kstream*,bool);
    uint32_t crc() const { return m_crc; }
    qu_scene_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // QU_SCENE_H_

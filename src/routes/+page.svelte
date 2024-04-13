<script>
    import Entry from "$lib/Entry.svelte";
    import folie_woche1 from "$lib/lessons/week1/test.txt";
    // const lessons = [
    //     {
    //         week: 1,
    //         files: [
    //             {
    //                 url: folie_woche1,
    //                 text: "Folien",
    //             },
    //         ],
    //     },
    // ];
    const lessons = []
</script>

<svelte:head>
    <title>Folien</title>
</svelte:head>

<div class="container">
    <div class="header">
        <div>
            <h1 class="title is-1 is-size-3-mobile" style="text-align: center;">
                Grundlagen: Rechenarchitektur
            </h1>
            <h1
                class="subtitle is-3 is-size-5-mobile"
                style="text-align: center;"
            >
                Sommersemester 2024 | Lukas Ketzer
            </h1>
        </div>

        <div class="links">
            <a href="https://github.com/lukasketzer" class="navbar-item">
                <span class="icon-text">
                    <span class="icon">
                        <i class="bi bi-github"></i>
                    </span>
                    Github
                </span>
            </a>
            <a href="mailto:lukas.a.ketzer@tum.de" class="navbar-item">
                <span class="icon-text">
                    <span class="icon">
                        <i class="bi bi-envelope"></i>
                    </span>
                    lukas.a.ketzer@tum.de
                </span>
            </a>
            <div>
                <p class="navbar-item">Zulip: Lukas Ketzer</p>
            </div>
        </div>
    </div>

    <div id="entries">
        <div class="box" style="width: 70%">
            <h1 class="title is-size-5-mobile">Nützliche Links</h1>
            <hr />
            <a
                href="/ssh"
                class="button is-outlined is-warning is-rounded is-inverted block"
            >
                SSH Guide
            </a>

            <a
                href="https://gra.caps.in.tum.de/"
                class="button is-outlined is-warning is-rounded is-inverted block"
            >
                GRA-Website
            </a>
            <a
                href="https://www.felixcloutier.com/x86/"
                class="button is-outlined is-warning is-rounded is-inverted block"
            >
                x86 instructions
            </a>
            <a
                href="https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#"
                class="button is-outlined is-warning is-rounded is-inverted block"
            >
                Intel intrinsic
            </a>
            <a
                href="https://githowto.com/"
                class="button is-outlined is-warning is-rounded is-inverted block"
            >
                GitHowTo
            </a>
        </div>

        {#if lessons.length == 0}
            No entries yet
        {:else}
            {#each lessons as lesson}
                <Entry week={lesson.week} files={lesson.files} />
            {/each}
        {/if}
    </div>
</div>

<style>
    #entries {
        display: flex;
        align-items: center;
        justify-content: center;
        flex-direction: column;
    }
    .links {
        display: flex;
        justify-content: center;
        align-self: center;
        flex-direction: row;
        flex-wrap: wrap;
    }
    .icon {
        padding-bottom: 3px;
    }
    .header {
        margin-top: 5em;
        margin-bottom: 5em;
    }
</style>

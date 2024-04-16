<script>
    export let name;

</script>

<div class="header">
    <div>
        <h1 class="title is-1 is-size-3-mobile" style="text-align: center;">
            Grundlagen: Rechenarchitektur
        </h1>
        <h1 class="subtitle is-3 is-size-5-mobile" style="text-align: center;">
            Sommersemester 2024 | {name}
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

<style>
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
